#include <stdio.h>
 int arr[]={100};
// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Traverse through all elements in the array
    for (i = 0; i < n; i++) {
        // Last i elements are already in place, so no need to check them
        for (j = 0; j < n-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    //int arr[] = {64, 34, 25, 12, 22, 11, 90};
  // int n = sizeof(arr)/sizeof(int);
   int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array of size n

    printf("Enter the elements to be sorted: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);

   bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

