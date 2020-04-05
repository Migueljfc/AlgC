#include<stdio.h>
#include<assert.h>

int recCalls = -1;

int T1(int n){
    assert(n >= 0);
    recCalls++;
    if(n == 0){
        return 0;
    }
    return T1(n/3) + n;
}

int T2(int n){
    assert(n >= 0);
    recCalls++;
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    return T2(n/3) + T2((n+2)/3) + n;
}

int T3(int n){
    assert(n >= 0);
    recCalls++;
    if(n == 0 || n == 1 || n == 2){
        return n;
    }
    else{
        if(n%3 == 0){
            return 2*T3(n/3)+n;
        }
        return T3(n/3) + T3((n+2)/3) + n;    
    }
}

int main(void){
    for(int i = 0; i < 29; i++){
        printf("i = %2d%3c|",i,' ');
        int a = T1(i);
        printf("T1 : %2d nº chamadas: %2d | ",a,recCalls);
        recCalls = -1;
        int b = T2(i);
        printf("T2 : %2d nº chamadas: %2d | ",b,recCalls);
        recCalls = -1;
        int c = T3(i);
        printf("T3 : %2d nºchamadas: %2d \n",c,recCalls);
        recCalls = -1;
    }
}