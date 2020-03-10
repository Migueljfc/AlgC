#include <stdio.h>
unsigned int nComp = 0;
unsigned int countElements(int array[],int n){
    int count = 0;
    int p_count = 1;
    int maior = -1;
    for(int i = n - 1; i > 0;i--){
        for(int j = 0;j < i;j++){
            if(array[i] > array[j]){
                count++; 
            }
            nComp++;
        }
        if(count >= p_count){
            maior = i;
            p_count = count;
        }
       
        if(p_count > i - 1){
            return maior;
        }
    
        count = 0;
    }
    return maior;
}
int main(void){
    int array[10]  =  {1,  9,  2,  8,  3,  4,  5,  3,  7,  2};
    size_t n = sizeof(array)/sizeof(int);
    int indice = countElements(array,n);
    printf("%d - %d\n",indice,nComp);
    printf("_________________________\n");
    nComp = 0;
    int array2[10]  =  {1,2,3,4,5,6,7,8,9,10};
    indice = countElements(array2,n);
    printf("%d - %d\n",indice,nComp);
    printf("_________________________\n");
    nComp = 0;
    int array3[10]  =  {2,2,2,2,2,2,2,2,2,2};
    indice = countElements(array3,n);
    printf("%d - %d\n",indice,nComp);
     printf("_________________________\n");
    nComp = 0;
    int array4[10]  =  {2,2,2,2,2,2,2,2,8,2};
    indice = countElements(array4,n);
    printf("%d - %d\n",indice,nComp);
}