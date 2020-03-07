#include<stdio.h>
int main(void)
{
    char name[20];
    puts("Nome");
    fgets(name,20,stdin);
    printf("Hello %s ",name);

    return 0;
}