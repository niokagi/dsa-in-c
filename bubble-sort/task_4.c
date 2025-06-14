#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
#define N 5

typedef struct
{
    char nrp[10];
    char nama[20];
    int kelas;
} Mahasiswa;

void printHeader(void)
{
    printf("%-10s %-20s %-5s\n", "NRP", "Nama", "Kelas");
    printf("--------------------------------------\n");
}

void printArr(Mahasiswa arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-10s %-20s %-5d\n",
               arr[i].nrp,
               arr[i].nama,
               arr[i].kelas);
    }
    putchar('\n');
}

void BubbleSortMahasiswa(Mahasiswa arr[], int n)
{
    Mahasiswa tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].nrp, arr[j + 1].nrp) > 0)
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void BubbleSortFlagMahasiswa(Mahasiswa arr[], int n)
{
    Mahasiswa tmp;
    for (int i = 0; i < n - 1; i++)
    {
        bool did_swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].nrp, arr[j + 1].nrp) > 0)
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                did_swap = true;
            }
        }
        if (!did_swap)
            break;
    }
}

void ShellSortMahasiswa(Mahasiswa arr[], int n)
{
    Mahasiswa tmp;
    int gap = n;
    while (gap > 1)
    {
        gap /= 2;
        bool did_swap = true;
        while (did_swap)
        {
            did_swap = false;
            for (int i = 0; i + gap < n; i++)
            {
                if (strcmp(arr[i].nrp, arr[i + gap].nrp) > 0)
                {
                    tmp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = tmp;
                    did_swap = true;
                }
            }
        }
    }
}

int main(void)
{
    Mahasiswa data_awal[N] = {
        {"31201", "Adhim", 1},
        {"10325", "Niokagi", 2},
        {"31109", "Chloe", 3},
        {"41109", "Cello", 3},
        {"31089", "Castro", 2}};
    Mahasiswa m1[N], m2[N], m3[N];

    printf("Data Awal:\n");
    printHeader();
    printArr(data_awal, N);

    // bubble
    memcpy(m1, data_awal, sizeof data_awal);
    BubbleSortMahasiswa(m1, N);
    printf("Hasil Bubble Sort:\n");
    printHeader();
    printArr(m1, N);

    // bubble w flag
    memcpy(m2, data_awal, sizeof data_awal);
    BubbleSortFlagMahasiswa(m2, N);
    printf("Hasil Bubble Sort Flag:\n");
    printHeader();
    printArr(m2, N);

    // shell
    memcpy(m3, data_awal, sizeof data_awal);
    ShellSortMahasiswa(m3, N);
    printf("Hasil Shell Sort:\n");
    printHeader();
    printArr(m3, N);

    return 0;
}
