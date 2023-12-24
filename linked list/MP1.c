#include <stdio.h>

//program that creates the summation of squares from 1 to N

int sum_of_squares_iterative(int n){
    int result = 0;
    for(int i = 1; i <= n; i++){
        result += i* i;
    }
    return result; 
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int sum = sum_of_squares_iterative(num);
    printf("The total sum is %d", sum);
}