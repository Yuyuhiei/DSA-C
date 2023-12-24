#include <stdio.h>

int main(){
    int i, j, temp, n, arr[10];
 printf("Enter the number of elements to be sorted: ");
 scanf("%d", &n);
 for(i = 0; i < n; i++){
    printf("Enter element number %d: ", i+1);
    scanf("%d", &arr[i]);
 }
    printf("Sorted Array: \n");
    for(j = 0; j < n-i-1; j++){
        if( arr[j] > arr[j+1])
        {
    temp = arr[j]; //=7
    arr[j] = arr[j+1]; //=8
    arr[j+1] = temp; //=8
        }
    printf("%d\n", temp);
    }
 }


 