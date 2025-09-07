#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct
{
    char nrp[10];
    char nama[20];
    int kelas;
} Mahasiswa;

void insertSort(Mahasiswa arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Mahasiswa key = arr[i]; // 1
        int j = i - 1;          // 0
        while (j >= 0 && strcmp(arr[j].nrp, key.nrp) > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectSort(Mahasiswa arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_indeks = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].nrp, arr[min_indeks].nrp) < 0)
            {
                min_indeks = j;
            }
        }
        if (min_indeks != i)
        {
            Mahasiswa temp = arr[i];
            arr[i] = arr[min_indeks];
            arr[min_indeks] = temp;
        }
    }
}

void printMhs(Mahasiswa arr[], int n)
{
    printf("%-10s %-20s %s\n", "NRP", "Nama", "Kelas");
    puts("-------------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("%-10s %-20s %d\n",
               arr[i].nrp, arr[i].nama, arr[i].kelas);
    }
    puts("");
}

int main(){
    Mahasiswa mhs[MAX] = {
        {"42010005", "Karl Marx", 1},
        {"42010020", "Beethoven", 2},
        {"52010001", "N Copernicus", 1},
        {"10100212", "Muhammad", 2},
        {"42010015", "Adhim Niokagi", 3}};

    printf("Data asli (sebelum terurut):\n");
    printMhs(mhs, MAX);

    Mahasiswa arr1[MAX];
    for (int i = 0; i < MAX; i++)
    {
        arr1[i] = mhs[i];
    }
    insertSort(arr1, MAX);
    printf("Setelah Insertion Sort (berdasarkan NRP ascending):\n");
    printMhs(arr1, MAX);

    Mahasiswa arr2[MAX];
    for (int i = 0; i < MAX; i++){
        arr2[i] = mhs[i];
    }
    selectSort(arr2, MAX);
    printf("Setelah Selection Sort (berdasarkan NRP ascending):\n");
    printMhs(arr2, MAX);

    return 0;
}
