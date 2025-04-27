#include <stdio.h>

int main(){
    char x=0xff;
    unsigned char y=0xff;
    printf("x: 0x%x, %d , %u\n",x,x,x);
    printf("y: 0x%x, %d , %u\n",y,y,y);

    printf("x>>2: 0x%x, %d , %u\n",x>>2,x>>2,x>>2);
    printf("y>>2: 0x%x, %d , %u\n",y>>2,y>>2,y>>2);
    return 0;
}
