#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main(){
    int menor,maior,space;
    printf("Digite o menor ângulo: \n");
    scanf("%d", &menor);
    printf("Digite o maior ângulo: \n");
    scanf("%d",&maior);
    printf("Digite o espaçamento entre os ângulos: \n");
    scanf("%d",&space);
    printf("ang  sin(ang)      cos(ang)\n");
    printf("----------------------------\n");
    for (int i = menor; i <= maior; i+= space){
        double radian = i*(PI/180);
        printf("%d  |%.9f  |%.9f\n",i,sin(radian),cos(radian));
    } 
    return 0;
}