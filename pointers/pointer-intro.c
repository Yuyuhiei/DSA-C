#include <stdio.h>

int main(){

    int* ptr, var = 10;

    ptr = &var;
    printf("%d\n", *ptr);
    printf("%d\n", var);
    printf("%p\n", &ptr);
    printf("%p\n", ptr);
    printf("%p\n", var);
    printf("%p\n", &var);

    return 0;



}