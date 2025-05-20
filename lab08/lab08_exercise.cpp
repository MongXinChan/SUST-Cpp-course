// Example Framework
#include <iostream>
#include <vector>
#include <chrono> // For timing
#include <numeric> // For std::iota (optional)
#include <cstdlib> // For aligned_alloc, free
#include <cmath>   // For std::abs (in result verification)

// If using AVX2
#ifdef WITH_AVX2
#include <immintrin.h>
#endif

// If using NEON
#ifdef WITH_NEON
#include <arm_neon.h>
#endif

// If using OpenMP
#ifdef _OPENMP
#include <omp.h>
#endif

const size_t VECTOR_SIZE = 2000000; // 2 million

// Function: Pure C++ vector addition
void vector_add_cpp(float* c, const float* a, const float* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
}

// Function: AVX2 vector addition (Example)
#ifdef WITH_AVX2
void vector_add_avx2(float* c, const float* a, const float* b, size_t n) {
    size_t n_aligned_part = (n / 8) * 8; // Process the part divisible by 8

    for (size_t i = 0; i < n_aligned_part; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i); // Use loadu for potentially unaligned memory
        __m256 vb = _mm256_loadu_ps(b + i);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_storeu_ps(c + i, vc);      // Use storeu
    }
    // Handle the remaining elements if n is not a multiple of 8
    for (size_t i = n_aligned_part; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
}

// Function: AVX2 + OpenMP vector addition (Example)
void vector_add_avx2_omp(float* c, const float* a, const float* b, size_t n_orig) {
    size_t n_parallel_part = (n_orig / 8) * 8; // Part to be processed in parallel

    #pragma omp parallel for
    for (size_t i = 0; i < n_parallel_part; i += 8) {
        __m256 va = _mm256_loadu_ps(a + i);
        __m256 vb = _mm256_loadu_ps(b + i);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_storeu_ps(c + i, vc);
    }
    // Handle the remaining elements serially after the parallel loop
    for (size_t i = n_parallel_part; i < n_orig; ++i) {
        c[i] = a[i] + b[i];
    }
}
#endif


// ... (NEON version implementation would be similar) ...

int main() {
    // --- Memory Allocation ---
    // Consider alignment: AVX2 typically needs 32-byte alignment (256-bit)
    // C++17 aligned_alloc
    float* vec_a = static_cast<float*>(aligned_alloc(32, VECTOR_SIZE * sizeof(float)));
    float* vec_b = static_cast<float*>(aligned_alloc(32, VECTOR_SIZE * sizeof(float)));
    float* vec_c_cpp = static_cast<float*>(aligned_alloc(32, VECTOR_SIZE * sizeof(float)));
    float* vec_c_simd = static_cast<float*>(aligned_alloc(32, VECTOR_SIZE * sizeof(float)));
    float* vec_c_simd_omp = static_cast<float*>(aligned_alloc(32, VECTOR_SIZE * sizeof(float)));

    if (!vec_a || !vec_b || !vec_c_cpp || !vec_c_simd || !vec_c_simd_omp) {
        std::cerr << "Memory allocation failed!" << std::endl;
        // Clean up any successfully allocated memory
        if(vec_a) free(vec_a);
        if(vec_b) free(vec_b);
        if(vec_c_cpp) free(vec_c_cpp);
        if(vec_c_simd) free(vec_c_simd);
        if(vec_c_simd_omp) free(vec_c_simd_omp);
        return 1;
    }

    // --- Initialize Vectors ---
    for (size_t i = 0; i < VECTOR_SIZE; ++i) {
        vec_a[i] = static_cast<float>(i);
        vec_b[i] = static_cast<float>(VECTOR_SIZE - 1 - i);
    }

    // --- Pure C++ Version ---
    auto start_cpp = std::chrono::high_resolution_clock::now();
    vector_add_cpp(vec_c_cpp, vec_a, vec_b, VECTOR_SIZE);
    auto end_cpp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_cpp = end_cpp - start_cpp;
    std::cout << "CPP version duration: " << duration_cpp.count() << " ms" << std::endl;

    // --- SIMD Version (AVX2 Example) ---
#ifdef WITH_AVX2
    auto start_avx2 = std::chrono::high_resolution_clock::now();
    vector_add_avx2(vec_c_simd, vec_a, vec_b, VECTOR_SIZE);
    auto end_avx2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_avx2 = end_avx2 - start_avx2;
    std::cout << "AVX2 version duration: " << duration_avx2.count() << " ms" << std::endl;

    // Verify results (simple sampling)
    bool avx2_correct = true;
    for(size_t i=0; i<VECTOR_SIZE; ++i) {
        if (std::abs(vec_c_cpp[i] - vec_c_simd[i]) > 1e-5) { // Use tolerance for floating-point comparison
            avx2_correct = false;
            std::cerr << "AVX2 Mismatch at index " << i << ": cpp=" << vec_c_cpp[i] << ", simd=" << vec_c_simd[i] << std::endl;
            break;
        }
    }
    std::cout << "AVX2 results are " << (avx2_correct ? "correct." : "INCORRECT!") << std::endl;


    // --- SIMD + OpenMP Version (AVX2 Example) ---
    #ifdef _OPENMP
    auto start_avx2_omp = std::chrono::high_resolution_clock::now();
    vector_add_avx2_omp(vec_c_simd_omp, vec_a, vec_b, VECTOR_SIZE);
    auto end_avx2_omp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_avx2_omp = end_avx2_omp - start_avx2_omp;
    std::cout << "AVX2 + OpenMP version duration: " << duration_avx2_omp.count() << " ms" << std::endl;

    bool avx2_omp_correct = true;
    for(size_t i=0; i<VECTOR_SIZE; ++i) {
        if (std::abs(vec_c_cpp[i] - vec_c_simd_omp[i]) > 1e-5) {
            avx2_omp_correct = false;
            std::cerr << "AVX2+OMP Mismatch at index " << i << ": cpp=" << vec_c_cpp[i] << ", simd_omp=" << vec_c_simd_omp[i] << std::endl;
            break;
        }
    }
    std::cout << "AVX2 + OpenMP results are " << (avx2_omp_correct ? "correct." : "INCORRECT!") << std::endl;
    #endif // _OPENMP
#endif // WITH_AVX2

    // ... (NEON version tests would be similar) ...

    // --- Free Memory ---
    free(vec_a);
    free(vec_b);
    free(vec_c_cpp);
    free(vec_c_simd);
    free(vec_c_simd_omp);

    return 0;
}