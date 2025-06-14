#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void swap_idx(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Partition(int arr[], int p, int r){
    int pivot = arr[p];
    int i = p;
    int j = r;
    while (i <= j){
        while (arr[j] > pivot)
            j--;
        while (arr[i] < pivot)
            i++;
        if (i < j){
            swap_idx(arr, i, j);
            i++;
            j--;
        }
        else
            return j;
    }
    return j;
}

void QuickSort(int arr[], int p, int r)
{
    if (p < r){
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q);
        QuickSort(arr, q + 1, r);
    }
}

int PartitionDesc(int arr[], int p, int r)
{
    int pivot = arr[p];
    int i = p;
    int j = r;
    while (i <= j){
        while (arr[j] < pivot)
            j--;
        while (arr[i] > pivot)
            i++;
        if (i < j){
            swap_idx(arr, i, j);
            i++;
            j--;
        }
        else
            return j;
    }
    return j;
}

void QuickSortDesc(int arr[], int p, int r){
    if (p < r){
        int q = PartitionDesc(arr, p, r);
        QuickSortDesc(arr, p, q);
        QuickSortDesc(arr, q + 1, r);
    }
}

int main(){
    int data_awal[MAX];
    int data_urut[MAX];
    int i;
    clock_t start, end;
    double duration;
    srand(time(NULL));

    printf("Data awal:\n");
    for (i = 0; i < MAX; i++){
        data_awal[i] = rand() % 100 + 1;
        printf("%2d ", data_awal[i]);
    }
    printf("\n\n");

    // asc
    for (i = 0; i < MAX; i++){
        data_urut[i] = data_awal[i];
    }
    start = clock();
    QuickSort(data_urut, 0, MAX - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Ascending:\n");
    for (i = 0; i < MAX; i++){
        printf("%2d ", data_urut[i]);
    }
    printf("\nWaktu Asc = %.3f detik\n\n", duration);

    // desc
    for (i = 0; i < MAX; i++){
        data_urut[i] = data_awal[i];
    }
    start = clock();
    QuickSortDesc(data_urut, 0, MAX - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Descending:\n");
    for (i = 0; i < MAX; i++){
        printf("%2d ", data_urut[i]);
    }
    printf("\nWaktu Desc = %.3f detik\n", duration);

    return 0;
}
