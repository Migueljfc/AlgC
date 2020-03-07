#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Digite o número de linhas da tabela:\n");
    scanf("%d",&n);
    printf("número  | quadrado| raiz quadrada|\n");
    printf("__________________________________\n");
    for(int i = 0;i < n;i++){
        printf("%d \t| %d \t  |%f \t |\n",i, i*i,sqrt(i));
    }
    return 0;
}