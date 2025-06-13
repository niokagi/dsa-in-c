#include <stdio.h>
#include <stdlib.h>

void cetakArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort(int arr[], int L, int R)
{
    if (L >= R)
        return;

    int i = L, j = R;
    int pivot = arr[(L + R) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (L < j)
        quickSort(arr, L, j);
    if (i < R)
        quickSort(arr, i, R);
}

int binarySearch(int arr[], int n, int kunci)
{
    int L = 0, R = n - 1;
    int iterasi = 0;

    while (L <= R)
    {
        iterasi++;
        int m = L + (R - L) / 2;

        printf("\nIterasi ke-%d:\n", iterasi);
        printf("Jangkauan pencarian: indeks %d sampai %d.\n", L, R);
        printf("Pengecekan di indeks tengah: arr[%d] = %d.\n", m, arr[m]);

        if (arr[m] == kunci)
        {
            printf("Hasil: Data %d ditemukan!\n", kunci);
            return m;
        }
        else if (kunci < arr[m])
        {
            printf("Aksi: Kunci (%d) < Nilai tengah (%d). Cari ke kiri.\n", kunci, arr[m]);
            R = m - 1;
        }
        else
        {
            printf("Aksi: Kunci (%d) > Nilai tengah (%d). Cari ke kanan.\n", kunci, arr[m]);
            L = m + 1;
        }
    }
    printf("Jangkauan L=%d sudah melewati R=%d.\n", L, R);
    return -1;
}

int main()
{
    int data[10];
    int max = 10;

    srand(0);
    printf("Data Awak : ");
    for (int i = 0; i < max; i++)
        data[i] = rand() % 50 + 1;
    cetakArray(data, max);

    quickSort(data, 0, max - 1);
    printf("Data Terurut: ");
    cetakArray(data, max);
    printf("\n");

    int kunci;
    printf("Masukkan data yg ingin dicari: ");
    scanf("%d", &kunci);

    int indeksKetemu = binarySearch(data, max, kunci);

    printf("\nHasil:\n");
    if (indeksKetemu != -1)
        printf("Data/kunci %d ditemukan pada indeks ke-%d.\n", kunci, indeksKetemu);
    else
        printf("Data/kunci %d tidak ditemukan dalam data array.\n", kunci);

    return 0;
}