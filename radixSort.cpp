#include "radixSort.h"

void CountingSort(data* A, data* B, int CurrentDigit, int fileSize)
{
    const int Digits = 10;
    int C[Digits], Quotient;

    int* ADigit = new int[fileSize + 1];

    for (int i = 0; i < Digits; i++)
        C[i] = 0;

    for (int j = 1; j <= fileSize; j++)
    {
        if (CurrentDigit == 1)
            ADigit[j] = A[j].key % 10;   // Extracts the 4 from the 14, 9 from 309, etc.
        else
        {  //*** Here we extract the 4 from 3541 and similar.
            int divisor = pow(10, CurrentDigit - 1);
            Quotient = A[j].key / divisor;   // For 3541, Quotient = 354.
            ADigit[j] = Quotient % 10;
        }
        C[ADigit[j]] = C[ADigit[j]] + 1;
    }
    // C[i] now contains the number of elements equal to i.


    for (int i = 1; i < Digits; i++)
        C[i] = C[i] + C[i - 1];
    // C[i] now contains the numbers of elements less or equal to i.

    for (int j = fileSize; j > 0; j--)
    {
        B[C[ADigit[j]]] = A[j];
        C[ADigit[j]] = C[ADigit[j]] - 1;
    }
}

void RadixSort(data* A, int d, int fileSize)
{
    int digit;

    data* B = new data[fileSize + 1];   // Array to temporarily hold the data.

    for (digit = 1; digit <= d; digit++)
    {
        CountingSort(A, B, digit, fileSize);
        // Now copy B to A. Note that this wastes some time, O(n) time, where n is the length of the array.
        // Note that the actual time wasted is proportional to n * d, but d is the (small) number of digits, so that the time is still O(n).
        for (int k = 0; k < fileSize + 1; k++)
            A[k] = B[k];
    }
}