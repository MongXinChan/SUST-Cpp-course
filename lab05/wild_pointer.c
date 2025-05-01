#include<stdio.h>   //wild_pointer.c
#include<stdlib.h>
int main(int argc, char* argv[]){
    int *p1;  //wild pointer
    // int *p1=NULL;
    *p1=0x12345678;
    printf("address: %p\tdata: 0x%x\n",p1,*p1);
    return 0;
}
