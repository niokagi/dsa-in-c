#include <stdio.h>

void insertSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int kanan = arr[i]; // 1 = 2
        int kiri = i - 1;   // 0 = 5

        while (kiri >= 0 && arr[kiri] > kanan)
        {
            arr[kiri + 1] = arr[kiri];
            kiri--; // -1 (memungkinkan pengecekan sampai ujung kiri array)
        }

        arr[kiri + 1] = kanan;
    }
}

int main()
{
    int arr[] = {5, 2, 9, 1, 6, 10};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    insertSort(arr, arrLength);

    printf("Data terurut : \n");
    for (int i = 0; i < arrLength; i++)
    {   
        printf("%d ", arr[i]);
    }

    return 0;
}