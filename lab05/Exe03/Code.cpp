#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int numA = 0x11223344;
    unsigned char byte0 = (unsigned char)(numA & 0xFF); // 提取最低有效字节

    // 检测系统字节序
    printf("Data A_addr: 0x%p, A_data: 0x%X, This is ", (void*)&numA, numA);
    if (byte0 == 0x44) {
        printf("LE\n"); // Little-Endian
    } else {
        printf("BE\n"); // Big-Endian
    }

    if(argc == 2){
        if(argv[1][0]=='H'){
            int *pnumB = (int*)malloc(sizeof(int));
            if(pnumB != NULL){
                // 堆模式：反转字节顺序
                *pnumB = ((numA >> 24) & 0xFF) | ((numA << 8) & 0xFF0000) | ((numA >> 8) & 0xFF00) | (numA << 24);
                printf("Data B_addr: 0x%p, B_data: 0x%X\n", (void*)pnumB, *pnumB);
                free(pnumB); // 释放分配的内存
            } else {
                printf("Memory allocation failed.\n");
            }
        }
        else if(argv[1][0]=='S'){
            // 栈模式：反转字节顺序
            int numB = ((numA >> 24) & 0xFF) | ((numA << 8) & 0xFF0000) | ((numA >> 8) & 0xFF00) | (numA << 24);
            printf("Data B_addr: 0x%p, B_data: 0x%X\n", (void*)&numB, numB);
        }
    }
    return 0;
}