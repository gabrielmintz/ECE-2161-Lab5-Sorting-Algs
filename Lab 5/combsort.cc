#include "../Lab 5/myheaders.h"

// Time Complexity: O(n^2), Ω(n^2 / p^2); Space Complexity: O(1)
// Nicholas Kunishige
void CombSort(long arr[], int n)
{
    // Shrink Factor for Comparison Gap
    const double shrink = 1.3;

    int gap = n, swaps = 0;

    do
    {
        // Decrease Gap by Factor of [shrink] Until Clamped at 1
        gap = int(double(gap) / shrink); if (gap < 1) gap = 1;

        // Reset Swap Counter
        swaps = 0;
        
        // Iterate until Right Side Reaches End
        for (int i = 0; i + gap < n; ++i)
        {
            // If Misordered, Swap the Values
            if (arr[i] > arr[i + gap])
            {
                long temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                // Increment Swap Counter to Indicate Array is Not Sorted
                ++swaps;
            }
        }
    } 
    while (swaps > 0);
}