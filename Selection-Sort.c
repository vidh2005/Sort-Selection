#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free

#define MALLOC(ptr, size, type) \
    ptr = (type *)malloc(size * sizeof(type));  \
    if (ptr == NULL) {  \
        printf("Insufficient space!\n");  \
        exit(1);  \
    }  // Macro for dynamic memory allocation with error handling

void selectionSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {   // traverses element one by one to compare with the rest
    int min_index = i; // index of the minimum value 
    for (int j = i + 1; j < size; j++) {  // the rest of the elements that will be compared to 
      if (array[j] < array[min_index]) // checking if second element is greater
        min_index = j; // changing the index of min value if second index is lower 
    }
    int temp = array[min_index]; // swapping 
    array[min_index] = array[i];
    array[i] = temp;
  }
}

int main() {
  int n;  // Variable to store total number of elements in the array
  int *data;  // Pointer to dynamically allocate memory for array

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Dynamic memory allocation for 'n' integers using the macro
  MALLOC(data, n, int);  // Macro checks for insufficient memory automatically
  
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);  // Inputting all elements of an array one by one
  }
  
  selectionSort(data, n); // Function call to perform sorting
  
  printf("Sorted array in Ascending Order:\n");
  for (int i = 0; i < n; i++) {
    printf("%d  ", data[i]);  // Printing the sorted elements of the array
  }
  printf("\n");

  free(data);  // free the dynamically allocated memory to prevent memory leak

  return 0;
}