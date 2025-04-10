#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n ; i++) {
        minIndex = i; // Assume the current index is the minimum

        // Find the actual minimum in the unsorted part
        for (j = i ; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        //}

        // Swap the found minimum with the current element
        //if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
   // int arr[] = {64, 25, 12, 22, 11};
//int n = sizeof(arr) / sizeof(arr[0]);

int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
