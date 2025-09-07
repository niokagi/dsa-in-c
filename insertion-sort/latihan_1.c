#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

void printArray(int arr[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int arrLength)
{
    for (int i = 1; i < arrLength; i++)
    {
        int kanan = arr[i]; // index ke-1
        int kiri = i - 1;   // index ke-0

        while (kiri >= 0 && arr[kiri] < kanan)
        {
            arr[kiri + 1] = arr[kiri];
            kiri--; // pengecekan sampai elemen ujung kiri
        }
        arr[kiri + 1] = kanan;
        printf("\n");
        printArray(arr);
    }
}

int main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;

    printf("Sebelum pengurutan : \n");
    srand(time(NULL));
    for (i = 0; i < MAX; i++)
    {
        data_awal[i] = rand() % 100 + 1; // 0 + 1, 1 - 100
        printf("%d ", data_awal[i]);
    }

    for (i = 0; i < MAX; i++)
    {
        data_urut[i] = data_awal[i];
    }

    insertionSort(data_urut, MAX);
    printf("\n\nArray ter-urut (Descending)\n");
    printArray(data_urut);

    return 0;
}