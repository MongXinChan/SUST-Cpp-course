#include "fun.h"

int main(){
    int a[]={1,2,3,4,5};
    int b[]={10,2,1,-1,4};
    for(int i=0;i<5;i++){
        printf("Now is %d th,the max: %d",i,max(a[i],b[i]));
        printf("the min: %d\n",min(a[i],b[i]));
    }

    return 0;
}