#include <stdio.h>   // c_a_demo.c

int main(int argc, char*argv[]){
    if(argc ==1)
        printf("ONLY argv[0]:%s\n",argv[0]);
    else
        for(int i=0;i<argc;i++)
            printf("argv[%d]: %s\n",i, argv[i]);

    return 0;
}
