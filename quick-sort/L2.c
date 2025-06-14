#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void MergeFlag(int arr[], int left, int median, int right, int desc)
{
    int temp[MAX];
    int i = left;
    int j = median + 1;
    int k = left;

    while (i <= median && j <= right)
    {
        if ((!desc && arr[i] <= arr[j]) || (desc && arr[i] >= arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= median)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int idx = left; idx <= right; idx++)
        arr[idx] = temp[idx];
}

void MergeSortFlag(int arr[], int left, int right, int desc)
{
    if (left < right)
    {
        int median = (left + right) / 2;
        MergeSortFlag(arr, left, median, desc);
        MergeSortFlag(arr, median + 1, right, desc);
        MergeFlag(arr, left, median, right, desc);
    }
}

int main()
{
    int data_awal[MAX], data_urut[MAX];
    time_t t1, t2;

    srand(time(NULL));
    printf("Data awal:\n");
    for (int i = 0; i < MAX; i++)
    {
        data_awal[i] = rand() % 100 + 1;
        printf("%2d ", data_awal[i]);
    }
    printf("\n\n");

    for (int i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time(&t1);
    MergeSortFlag(data_urut, 0, MAX - 1, 0);
    time(&t2);
    printf("Sorted Ascending:\n");
    for (int i = 0; i < MAX; i++)
        printf("%2d ", data_urut[i]);
    printf("\nWaktu Asc  = %ld detik\n\n", (long)(t2 - t1));

    for (int i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time(&t1);
    MergeSortFlag(data_urut, 0, MAX - 1, 1);
    time(&t2);
    printf("Sorted Descending:\n");
    for (int i = 0; i < MAX; i++)
        printf("%2d ", data_urut[i]);
    printf("\nWaktu Desc = %ld detik\n", (long)(t2 - t1));

    return 0;
}
