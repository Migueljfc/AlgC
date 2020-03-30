#include <stdio.h>
#include <assert.h>

static int nComp= 0;
static int changes = 0;

void imprimir(int* array , int *n){
  printf(" {");
  for(int i = 0; i< *n ; i++){
      printf("%d, ",array[i]);
    }
  printf("} ->");
}

void Eliminate(int* array, int* n){
  assert(*n>1);
    for(int i = 0; i < *n ; i++){
        for(int j = i + 1; j < *n; ){
          nComp++;
          if(array[j] == array[i]){
            for(int k = j ; k < *n - 1;k++){
                array[k] = array[k + 1];
                changes++;
            }
          (*n)--;
          }else{
          j++;
          } 
        }  
    }
}



int main(void){
  int array[10] = {1,2,2,2,3,3,4,5,8,8};
  int n = sizeof(array)/ sizeof(int);
  imprimir(array,&n);
  Eliminate(array,&n);
  imprimir(array,&n);
  printf(" trocas: %d | nº Operações: %d",changes,nComp);
  changes = 0;
  nComp = 0;
  printf("\n \n");
  int array1[10] = {1,2,2,2,3,3,3,3,8,8};
  n =  sizeof(array1)/ sizeof(int);
  imprimir(array1,&n);
  Eliminate(array1,&n);
  imprimir(array1,&n);
  printf(" trocas: %d | nº Operações: %d",changes,nComp);
  changes = 0;
  nComp = 0;
  printf("\n \n");
  int array2[7] = {1,2,3,2,1,3,4};
  n = sizeof(array2)/sizeof(int);
  imprimir(array2,&n);
  Eliminate(array2,&n);
  imprimir(array2,&n);
  printf(" trocas: %d | nº Operações: %d",changes,nComp);
  changes = 0;
  nComp = 0;
  printf("\n \n");
  int array3[10] = {1,2,5,4,7,0,3,9,6,8};
  n = sizeof(array3)/sizeof(int);
  imprimir(array3,&n);
  Eliminate(array3,&n);
  imprimir(array3,&n);
  printf("trocas: %d | nº Operações: %d",changes,nComp);
  changes = 0;
  nComp = 0;
  printf("\n \n");
  int array4[10] = {1,1,1,1,1,1,1,1,1,1};
  n = sizeof(array4)/sizeof(int);
  imprimir(array4,&n);
  Eliminate(array4,&n);
  imprimir(array4,&n);
  printf("trocas: %d | nº Operações: %d",changes,nComp);
  changes = 0;
  nComp = 0;
 printf("\n");
 
}