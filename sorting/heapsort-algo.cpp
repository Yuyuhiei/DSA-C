#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    heapSort(arr, n);

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

//The heapify function takes an array, the size of the heap (n), and the index of the root node (i) as parameters. 
//It first assumes that the largest element is the root node. 
//It then compares the left and right children of the root node and if either of them is larger than the root,
// it sets the largest element to the child. Finally, if the largest element is not the root,
// it swaps the root with the largest child and recursively calls heapify on the new largest child 
//to maintain the heap property.

//The heapSort function first builds a max heap by calling heapify on all non-leaf nodes. 
//It then repeatedly extracts the maximum element from the heap by swapping it with the last element in the heap, 
//reducing the heap size by one, and calling heapify on the new root node. 
//The result is a sorted array in ascending order.

//In the main function, an example array is initialized, and the original and sorted arrays are printed to the console.