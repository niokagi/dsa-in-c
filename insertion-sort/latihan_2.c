#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void InsertionSort(int arr[])
{
    int i, j, key;
    for (i = 1; i < MAX; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSortDESC(int arr[])
{
    int i, j, max_indeks, temp;
    for (i = 0; i < MAX - 1; i++)
    {
        max_indeks = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[j] > arr[max_indeks])
            {
                max_indeks = j;
            }
        }
        temp = arr[i]; // tukar elemen
        arr[i] = arr[max_indeks];
        arr[max_indeks] = temp;
    }
}

int main()
{
    int data_awal[MAX], data_urut[MAX], i;
    long k1, k2;

    printf("Sebelum pengurutan : \n");
    srand(time(NULL));

    for (i = 0; i < MAX; i++)
    {
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    // insertion (asc)
    for (i = 0; i < MAX; i++)
    {
        data_urut[i] = data_awal[i];
    }

    printf("\n\nSetelah Insertion Sort (Ascending) : \n");
    time(&k1);
    InsertionSort(data_urut);
    time(&k2);

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_urut[i]);
    }
    printf("\nWaktu = %ld detik\n", k2 - k1);

    // selection (desc)
    for (i = 0; i < MAX; i++)
    {
        data_urut[i] = data_awal[i];
    }
    printf("\nSetelah Selection Sort (Descending) : \n");
    time(&k1);
    SelectionSortDESC(data_urut);
    time(&k2);

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_urut[i]);
    }
    printf("\nWaktu = %ld detik\n", k2 - k1);
    return 0;
}
