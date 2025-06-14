#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 20

void printArr(int arr[]){
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void BubbleSortAsc(int arr[]){
    int i, j, tmp;
    int prev[MAX];

    for (i = 0; i < MAX - 1; i++){
        memcpy(prev, arr, sizeof(prev));
        for (j = 0; j < MAX - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
        if (memcmp(prev, arr, sizeof(prev)) == 0)
            break;
        // printArr(arr);
    }
}

void BubbleSortDesc(int arr[]){
    int i, j, tmp;
    int prev[MAX];

    for (i = 0; i < MAX - 1; i++){
        memcpy(prev, arr, sizeof(prev));
        for (j = 0; j < MAX - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
        if (memcmp(prev, arr, sizeof(prev)) == 0)
            break;
        // printArr(arr);
    }
}

int main(){
    int data_awal[MAX], data_asc[MAX], data_desc[MAX];
    int i;
    clock_t t0, t1;
    double waktu;
    srand(time(NULL));

    for (i = 0; i < MAX; i++)
        data_awal[i] = rand() % 100 + 1;

    printf("Data awal:\n");
    printArr(data_awal);

    // asc
    for (i = 0; i < MAX; i++)
        data_asc[i] = data_awal[i];
    // printf("\nProses Bubble Sort Ascending:\n");
    
    t0 = clock();
    BubbleSortAsc(data_asc);
    t1 = clock();
    printf("\nHasil akhir Ascending:\n");
    printArr(data_asc);
    waktu = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Waktu eksekusi = %.3f detik\n", waktu);

    // desc
    for (i = 0; i < MAX; i++)
        data_desc[i] = data_awal[i];
    // printf("\nProses Bubble Sort Descending:\n");
    
    t0 = clock();
    BubbleSortDesc(data_desc);
    t1 = clock();
    printf("\nHasil akhir Descending:\n");
    printArr(data_desc);
    waktu = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Waktu eksekusi = %.3f detik\n", waktu);

    return 0;
}
