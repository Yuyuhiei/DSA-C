#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <mem.h>
#include <conio.h>

int my_variable = 80;

int main(){
    //dynamic
    int *x = (int *)malloc(sizeof(int));
    int *arr = (int *)malloc(sizeof(int)*100);

    *x = 120;
    arr[90] = 71;
    //arr[101] = 8// OUT OF BOUNDS. This is bad.

    double *darr;
    darr = (double *)calloc(sizeof(double), 100);
    //is the same as -- darr = malloc(sizeof(double)*100);

    darr = (double *)realloc(darr, sizeof(double)*500); 

    printf("%d\n", *x);
    darr[499] = 17.5;
    printf("%0.2f\n", darr[499]);
    printf("%d\n", arr[90]);

    free(arr);
    arr = NULL;
    free(darr);
    darr = NULL;

}