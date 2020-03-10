#include <stdio.h>

unsigned int nComp = 0;

int findGreatest(int array[],int n){
    int count = 0;      // variável que conta o número de elementos menores
    int p_count = 0;    // variável que guarda a última maior contagem
    int greatest = -1;     // indice do elemento com maiores elementos menores //que ele 

    for(int i = 1; i < n;i++){
        for(int j = 0;j < i;j++){
            if(array[i] > array[j]){
                count++;
                
            }
            nComp ++;
        }
        if(count > p_count){
            greatest = i;
            p_count = count;
        }
        count = 0;
    }
    return greatest;
}

int main(void){
    int array[10]  =   {2,2,2,2,2,2,2,2,2,2};
    size_t n = sizeof(array)/sizeof(int);
    int indice = findGreatest(array,n);
    printf("%d - %d \n",indice,nComp);
    
}
