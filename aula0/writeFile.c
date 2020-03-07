#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main(){
    FILE *fp;
    fp = fopen("/home/miguel/MEGAsync/2 ano/AlgC/aula0/test.txt","w+");
    int menor,maior,space;
    printf("Digite o menor ângulo: \n");
    scanf("%d", &menor);
    printf("Digite o maior ângulo: \n");
    scanf("%d",&maior);
    printf("Digite o espaçamento entre os ângulos: \n");
    scanf("%d",&space);
    fprintf(fp,"ang  sin(ang)      cos(ang)\n");
    fprintf(fp,"----------------------------\n");
    for (int i = menor; i <= maior; i+= space){
        double radian = i*(PI/180);
        fprintf(fp,"%d  |%.9f  |%.9f\n",i,sin(radian),cos(radian));
    } 
    fclose(fp);
}