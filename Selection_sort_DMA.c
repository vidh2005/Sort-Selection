#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n) {
    int i, j, minIndex, temp;
    
    // Iterate over each element
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        
        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    
    // Ask for the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array using selection sort
    selectionSort(arr, n);
    
    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}
