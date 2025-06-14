#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MHS 100

typedef struct
{
    char nrp[10];
    char nama[20];
    int kelas;
} Mahasiswa;

void swap_mhs(Mahasiswa a[], int i, int j)
{
    Mahasiswa temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void shellSortNrp(Mahasiswa arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            Mahasiswa temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap].nrp, temp.nrp) > 0; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

typedef struct Mahasiswa MahasiswaT;
void mergeNrp(Mahasiswa arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Mahasiswa *L = malloc(n1 * sizeof(Mahasiswa));
    Mahasiswa *R = malloc(n2 * sizeof(Mahasiswa));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].nrp, R[j].nrp) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortNrp(Mahasiswa arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortNrp(arr, left, mid);
        mergeSortNrp(arr, mid + 1, right);
        mergeNrp(arr, left, mid, right);
    }
}

void printMahasiswa(const char *judul, Mahasiswa arr[], int n)
{
    printf("%s\n", judul);
    printf("| %-10s | %-20s | %-5s |\n", "NRP", "Nama", "Kelas");
    printf("|------------|----------------------|-------|\n");
    for (int i = 0; i < n; i++)
        printf("| %-10s | %-20s | %-5d |\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
}

int main()
{
    Mahasiswa contoh[] = {
        {"20123456", "Adhim", 1},
        {"20123412", "Nioka", 2},
        {"20123489", "Muhammmad", 1},
        {"20123399", "Napoleon", 3},
        {"20123430", "Mozzart", 2}};
    int n = sizeof(contoh) / sizeof(contoh[0]);
    Mahasiswa data[MAX_MHS];

    memcpy(data, contoh, n * sizeof(Mahasiswa));
    printMahasiswa("Data Awal:", data, n);

    shellSortNrp(data, n);
    printMahasiswa("\nSetelah Shell Sort (berdasarkan NRP):", data, n);

    memcpy(data, contoh, n * sizeof(Mahasiswa));

    mergeSortNrp(data, 0, n - 1);
    printMahasiswa("\nSetelah Merge Sort (berdasarkan NRP):", data, n);

    return 0;
}
