#include<stdio.h>
#include<assert.h>

int nMult = 0;
 int motzkin(int n){
    assert(n >= 0);
    int result = 0;
    if(n == 0 || n == 1){
        result = 1;
    }
    else{
        for(int k = 0;k <= n-2;k++){
            nMult++;
            result += motzkin(k) * motzkin(n-2-k);
        }
        result += motzkin(n-1);
    }
    return result;

}

int main(void){
    printf("%3s| %10s | %6s \n","n","Recursiva","nMult");
    printf("_____________________________\n");
    for(int i = 0;i <= 15;i++){
        int n = motzkin(i);
        printf("%3d| %10d | %6d \n",i,n,nMult);
        nMult = 0;
    }
    return 0;

}