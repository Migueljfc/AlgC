#include <stdio.h>
#include "elapsed_time.h"
#include <math.h>

static int nops ;

unsigned int Precursiva(int n){
    if (n == 0){
        return 0;
        
    }
    if(n == 1){
        return 1;
        
    }
    nops++;
    return 3 * Precursiva(n - 1) + 2 * Precursiva(n - 2);  
}

unsigned int Piterativa(int n){
    int atual;
    int antant = 0;
    int ant = 1;

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    else{
        for(int i = 2;i<= n;i++){
            atual = 2 * antant + 3 * ant ;
            antant = ant;
            ant = atual;
            nops ++;
        }
        return atual;
    }
}
unsigned int Precorrencia(int n){
    nops++;
    return ((pow(0.5*(3+sqrt(17)),n))-(pow(0.5*(3-sqrt(17)),n)))/sqrt(17); 
}
unsigned int Precorrencia2(int n){
    nops++;
    return round(1/sqrt(17)*pow(0.5*(3 + sqrt(17)),n));
}

unsigned int Pexponencial(int n){
    nops++;
    return round(0.24253562503633297352*exp(1.27019663313689157536*n));
}

int main(void){
    int n ;
    double time;
    printf("Valor de n : ");
    scanf("%d",&n);
    printf(" ************************* RECURSIVA *************************\n");
    printf(" _____________________________________________________________ \n");
    printf("\n n \t| P(n)\t| time\t        |nº Oper\n");
    printf("___________________________________\n");
    for(int i = 0;i<=n;i++){
        elapsed_time();
        int r = Precursiva(i);
        time = elapsed_time();
        printf("%d\t|%d\t|%f\t|%d \n",i,r,time,nops);
        nops = 0;
    }

    printf(" ************************* ITERATIVA *************************\n");
    printf(" _____________________________________________________________ \n");
    printf("\n n \t| P(n)\t| time\t        |nº Oper\n");
    printf("___________________________________\n");
    for(int i = 0;i<=n;i++){
        elapsed_time();
        int r = Piterativa(i);
        time = elapsed_time();
        printf("%d\t|%d\t|%f\t|%d \n",i,r,time,nops);
        nops = 0;
    }

    printf(" ************************* RECORRÊNCIA *************************\n");
    printf(" _____________________________________________________________ \n");
    printf("\n n \t| P(n)\t| time\t        |nº Oper\n");
    printf("___________________________________\n");
    for(int i = 0;i<=n;i++){
        elapsed_time();
        int r = Precorrencia(i);
        time = elapsed_time();
        printf("%d\t|%d\t|%f\t|%d \n",i,r,time,nops);
        nops = 0;
    }

    printf(" ************************* RECORRÊNCIA2 *************************\n");
    printf(" _____________________________________________________________ \n");
    printf("\n n \t| P(n)\t| time\t        |nº Oper\n");
    printf("___________________________________\n");
    for(int i = 0;i<=n;i++){
        elapsed_time();
        int r = Precorrencia2(i);
        time = elapsed_time();
        printf("%d\t|%d\t|%f\t|%d \n",i,r,time,nops);
        nops = 0;
    }

    printf(" ************************* EXPONENCIAL *************************\n");
    printf(" _____________________________________________________________ \n");
    printf("\n n \t| P(n)\t| time\t        |nº Oper\n");
    printf("___________________________________\n");
    for(int i = 0;i<=n;i++){
        elapsed_time();
        int r = Pexponencial(i);
        time = elapsed_time();
        printf("%d\t|%d\t|%f\t|%d \n",i,r,time,nops);
        nops = 0;
    }
}