#include "../Lab 5/myheaders.h"

// Time Complexity: O(n); Space Complexity: O(n)
// Nicholas Kunishige
void radixSort(long arr[], int n)
{
    // Automatically Determine More Efficient Resolution (3 / 4; 8-bit Word / 16-bit Word)
    int res = (n > 65024 ? 4 : 3);

    // Number of Possible Values; [Max Value + 1]
    const long wP = (1 << (1 << res));

    // Secondary Temporary Array
    long* nv = new long[n];

    // Array Pointer Array (Makes Swapping Reference Arrays Easier)
    long* ptrs[2] = {arr, nv};

    // Iterates Over Every Word
    for (int i = 0; i < (64 >> res); ++i)
    {
        // Reference Value for Determining Appropriate Array
        bool curr = (i & 1);

        // Lookup Table for Amount of Each Value
        long* vCt = new long[wP]{};

        // First Pass; Populate vCt Lookup Table
        for (long* pti = ptrs[curr]; pti < ptrs[curr] + n; ++pti)
        {
            // Finds the Word Value Associated with the Appropriate Word Index
            long v = ((*pti) >> (i << res)) & (wP - 1);

            // Flips the MSB of the Number (Ensures Negative Numbers Appear Behind Positive Numbers)
            if ((i + 1) == (64 >> res)) v ^= (wP >> 1);

            // Increments Value's Count in Lookup
            ++vCt[v];
        }

        // Lookup Table Filled with Insertion Positions for Each Value 
        long* ins = new long[wP]{};
        
        // Populate Insertion Table with Last Location for Each Value
        for (long i = 0, sum = 0; i < wP; ++i)
        {
            sum += vCt[i];
            ins[i] = sum - 1;
        }

        // Second Pass; Place all Numbers Based on Value Distribution
        for (long* pti = ptrs[curr]; pti < ptrs[curr] + n; ++pti)
        {
            // Finds the Word Value Associated with the Appropriate Word Index
            long v = ((*pti) >> (i << res)) & (wP - 1);

            // Flips the MSB of the Number (Ensures Negative Numbers Appear Behind Positive Numbers)
            if ((i + 1) == (64 >> res)) v ^= (wP >> 1);

            // Fills New Array in FIFO Order (First Added; First Accessed in Next Iteration) [Last Insertion Position - Unplaced Values +x 1]
            ptrs[!curr][ins[v] - --vCt[v]] = *pti;
        }

        delete[] vCt, delete[] ins;
    }

    delete[] nv;
}