#include "../Lab 5/myheaders.h"


void bubbleSort(long arr[], int n) {
    bool swapped;

    // Outer loop for number of times through array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Inner loop for comparing adjacent elements, bubbles the largest
        // unsorted value to the end of current run
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps occurred during this pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}
