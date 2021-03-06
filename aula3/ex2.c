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
    int array[10]  =  {1,  9,  2,  8,  3,  4,  5,  3,  7,  2};
    size_t n = sizeof(array)/sizeof(int);
    int indice = findGreatest(array,n);
    printf("%d - %d\n",indice,nComp);
    printf("_________________________\n");
    nComp = 0;
    int array2[10]  =  {1,  7,  4,  6,  5,  2,  3,  2,  1,  0};
    indice = findGreatest(array2,n);
    printf("%d - %d\n",indice,nComp);
    printf("_________________________\n");
    nComp = 0;
    int array3[10]  =  {2,2,2,2,2,2,2,2,2,2};
    indice = findGreatest(array3,n);
    printf("%d - %d\n",indice,nComp);
     printf("_________________________\n");
    nComp = 0;
    int array4[5]  =  {2,2,2,2,5};
    n = sizeof(array4)/sizeof(int);
    indice = findGreatest(array4,n);
    printf("%d - %d\n",indice,nComp);
}
