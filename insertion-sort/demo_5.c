#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct
{
    char nrp[10];
    char nama[20];
    int kelas;
} Mahasiswa;

void swapMahasiswa(Mahasiswa *a, Mahasiswa *b)
{
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void insertSort(Mahasiswa arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Mahasiswa key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].nrp, key.nrp) > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printMhs(Mahasiswa arr[], int n)
{
    printf("%-16s %-20s %s\n", "NRP", "Nama", "Kelas");
    puts("------------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("%-16s %-20s %d\n", arr[i].nrp, arr[i].nama, arr[i].kelas);
    }
    puts("");
}

int main()
{
    Mahasiswa mhs[MAX] = {
        {"1010012", "Muhammad", 2},
        {"42010005", "Karl Marx", 1},
        {"42010020", "Beethoven", 2},
        {"52010001", "N Copernicus", 1},
        {"42010015", "Adhim Niokagi", 3}};

    printf("Data asli (sblm terurut):\n");
    printMhs(mhs, MAX);

    // insertion
    Mahasiswa arr1[MAX];
    memcpy(arr1, mhs, sizeof mhs);
    insertSort(arr1, MAX);
    printf("Stelah Insertion Sort (brdasar NRP ascending):\n");
    printMhs(arr1, MAX);

    // selection
    Mahasiswa arr2[MAX];
    memcpy(arr2, mhs, sizeof mhs);
    selectSort(arr2, MAX);
    printf("Stelah Selection Sort (brdasar NRP ascending):\n");
    printMhs(arr2, MAX);

    return 0;
}
