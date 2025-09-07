#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

void selectASC(int arr[])
{
    int i, j, maks_indeks, tmp;
    for (i = MAX - 1; i > 0; i--)
    {
        maks_indeks = 0;
        for (j = 1; j <= i; j++)
        {
            if (arr[j] > arr[maks_indeks])
            {
                maks_indeks = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[maks_indeks];
        arr[maks_indeks] = tmp;
    }
}

void selectDESC(int arr[])
{
    int i, j, min_idx, tmp;
    for (i = MAX - 1; i > 0; i--)
    {
        min_idx = 0;
        for (j = 1; j <= i; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

int main()
{
    int data_awal[MAX], data_sort[MAX], i;

    srand(time(NULL));
    printf("Data sblm terurut:\n");

    for (i = 0; i < MAX; i++)
    {
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }
    printf("\n\n");

    for (i = 0; i < MAX; i++)
    {
        data_sort[i] = data_awal[i];
    }
    selectASC(data_sort);
    printf("Stelah Selection Sort Ascending (kanan ke kiri):\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_sort[i]);
    }
    printf("\n\n");

    for (i = 0; i < MAX; i++)
    {
        data_sort[i] = data_awal[i];
    }
    selectDESC(data_sort);
    printf("Stelah Selection Sort Descending (kanan ke kiri):\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_sort[i]);
    }
    printf("\n");

    return 0;
}
