#include <stdio.h>

unsigned static int nComp = 0 ;

unsigned int countDif(int array[],int n){
    int ant = array[0];
    int countDif = 0;
    for(int i = 1; i < n;i++){
        if(array[i] != ant ){
            countDif++;
        }
        ant = array[i];
        nComp++;
    }
    return countDif;
}
int main(void){
    int array[10]  = {4,5,1,2,6,8,7,9,3,0};
    size_t n = sizeof(array)/sizeof(int);
    int count = countDif(array,n);
    printf("count = %d Nº Comp =  %d \n",count,nComp);

}

