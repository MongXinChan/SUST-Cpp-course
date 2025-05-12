#include <iostream>
int add(int a, int b) {
    return a + b;
}

int main(){
    int x=0, y=0,z=0;
    int (*func_ptr)(int, int) = add;
    printf("address of data:x:%p,y_address:%p\n",&x,&y);
    printf("address of func\"main\":%p\n",main);
    printf("address of func\"printf\":%p\n",printf);
    x=add(1,2);
    printf("address of func\"add\":%p\n",add);
    y=add(10,20);
    printf("address of func\"add\":%p\n",add);
    z=func_ptr(100,200);
    printf("address of func_ptr:%p\n",func_ptr);
    return 0;
}