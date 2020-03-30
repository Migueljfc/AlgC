#include <stdio.h>
#include <assert.h>

unsigned int nComp = 0;
int isArith(int a[], int n){
    assert(n>1);
    for(int i = 0;i < n-1; i++){
        if(a[i+1]-a[i] != 1){
            nComp++;
            return 0;
        }
        nComp++;

    }
    return 1;
}

int main(void){
    int array[10] = {1, 3, 4, 5, 5, 6, 7, 7, 8, 9};
    size_t n = sizeof(array)/sizeof(int);
    int c = isArith(array,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array1[10] = {1,2,4,5,5,6,7,8,8,9};
    c = isArith(array1,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array2[10] = {1,2,3,6,8,8,8,9,9,9};
    c = isArith(array2,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array3[10] ={1,2,3,4,6,7,7,8,8,9};
    c = isArith(array3,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array4[10] = {1, 2, 3, 4, 5, 7, 7, 8, 8, 9};
    c = isArith(array4,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array5[10] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 9};
    c = isArith(array5,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array6[10] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 9};
    c = isArith(array6,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array7[10] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9};
    c = isArith(array7,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array8[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    c = isArith(array8,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;
    int array9[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    c = isArith(array9,n);
    printf("aritmetica : %d - nComp: %d\n",c,nComp);
    nComp = 0;

    


}
