#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

void printArr(int arr[])
{
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

// asc
void ShellSort(int arr[])
{
    int i, jarak, temp;
    bool did_swap;

    jarak = MAX;
    while (jarak > 1)
    {
        jarak /= 2;
        did_swap = true;
        while (did_swap)
        {
            did_swap = false;
            for (i = 0; i < MAX - jarak; i++)
            {
                if (arr[i] > arr[i + jarak])
                {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;
                }
            }
        }
        printArr(arr);
    }
}

//
void ShellSortDesc(int arr[])
{
    int i, jarak, temp;
    bool did_swap;

    jarak = MAX;
    while (jarak > 1)
    {
        jarak /= 2;
        did_swap = true;
        while (did_swap)
        {
            did_swap = false;
            for (i = 0; i < MAX - jarak; i++)
            {
                if (arr[i] < arr[i + jarak])
                {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;
                }
            }
        }
        printArr(arr);
    }
}

int main()
{
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
    memcpy(data_asc, data_awal, sizeof data_awal);
    printf("\nProses Shell Sort Ascending:\n");
    t0 = clock();
    ShellSort(data_asc);
    t1 = clock();
    printf("\nHasil akhir Ascending:\n");
    printArr(data_asc);
    waktu = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Waktu eksekusi ASC = %.3f detik\n", waktu);

    // desc
    memcpy(data_desc, data_awal, sizeof data_awal);
    printf("\nProses Shell Sort Descending:\n");
    t0 = clock();
    ShellSortDesc(data_desc);
    t1 = clock();
    printf("\nHasil akhir Descending:\n");
    printArr(data_desc);
    waktu = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("Waktu eksekusi DESC = %.3f detik\n", waktu);

    return 0;
}
