#include <stdio.h>

int main(){
    char s[50];
    fgets(s,50,stdin);
    printf("You entered: ");
    puts(s); //The puts() function is used to display output as a string.
    
    return 0;


}