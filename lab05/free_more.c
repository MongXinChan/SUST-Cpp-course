#include <stdio.h>    //free more
#include <stdlib.h>
int main(int argc, char*argv[]){
    int *p1 = (int *)malloc(sizeof(int)*1);
    *p1=0x12345678;
    int *p2 = p1;
    printf("p1:%p\tdata:0x%x\n"
           "p2:%p\tdata:0x%x\n",p1,*p1,p2,*p2);
    free(p1);
    free(p2);
    return 0;
}
