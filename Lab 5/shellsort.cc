#include "../Lab 5/myheaders.h"


void shellSort(long arr[], int n) {
    // Large gap, reduce the gap by half each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Perform gapped insertion sort for current gap size
        for (int i = gap; i < n; i++) {
            long temp = arr[i];
            int j;

            // Shift sorted elements up until correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Place temp in its correct sorted position
            arr[j] = temp;
        }
    }
}

