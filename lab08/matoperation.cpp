#include <iostream>
#include "matoperation.hpp"

#ifdef WITH_AVX2
#include <immintrin.h>
#endif

#ifdef WITH_NEON
#include <arm_neon.h>

#ifdef _OPENMP
#include <omp.h>
#endif