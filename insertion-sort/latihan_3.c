#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void insertASC(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] < key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

void insertDESC(int arr[])
{
    int i, j, key;
    for (i = MAX - 2; i >= 0; i--)
    {
        key = arr[i];
        j = i + 1;
        while (j < MAX && arr[j] > key)
        {
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
    }
}

int main()
{
    int data_awal[MAX], data_sort[MAX], i;

    srand(time(NULL));
    printf("Data sebelum pengurutan:\n");

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
    insertASC(data_sort);
    printf("Setelah Insertion Sort (Ascending):\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_sort[i]);
    }
    printf("\n\n");

    for (i = 0; i < MAX; i++)
    {
        data_sort[i] = data_awal[i];
    }
    insertDESC(data_sort);
    printf("Setelah Insertion Sort (Descending):\n");

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", data_sort[i]);
    }
    printf("\n");

    return 0;
}
