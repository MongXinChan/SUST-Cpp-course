#include <stdio.h>

int main(int argc, char*argv[]){
    char uname[10]={""};
    char dname[10]={""};
    char cname[10]={""};
    printf("please input the name of University: ");
    scanf("%s", uname); 
    printf("please input the name of department: ");
    scanf("%s", dname);
    printf("please input the name of course: ");
    scanf("%s", cname);     
    printf("uname: %s, dname: %s, cname:%s\n",uname,dname,cname);  
    return 0;
}
