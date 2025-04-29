#include <stdio.h>

int main(){
    int prj_id=0;
    float prj_sc=0.0f;
    char valid=0;
    printf("please input 'project id' in decimal int: ");
    scanf("%d", &prj_id); 
    printf("please input the score : ");
    scanf("%f", &prj_sc);
    printf("please input the score is valid or not(Y/N): ");
    while (getchar() != '\n');
    scanf("%c", &valid);     
    printf("project id: %d, score: %.1f, %s\n",
               prj_id, prj_sc, (valid=='y'||valid=='Y')?"VALID":"NOT VALIDE" );  
    return 0;
}
