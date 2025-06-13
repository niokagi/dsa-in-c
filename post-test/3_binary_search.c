#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target)
{
    int kiri = 0;
    int kanan = n - 1;

    while (kiri <= kanan)
    {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target)
            return tengah;

        if (arr[tengah] < target)
            kiri = tengah + 1;

        else
            kanan = tengah - 1;
    }
    return -1;
}

void cetakArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int tiket[] = {1102, 1032, 1133, 1088, 1110, 1045, 1150};
    int n = 7;
    int target = 1088;

    printf("Mencari nomor tiket: %d\n", target);
    printf("Data Awal (belum urut): ");
    cetakArray(tiket, n);

    bubbleSort(tiket, n);
    printf("Data Setelah Diurutkan  : ");
    cetakArray(tiket, n);
    printf("\n");

    int posisi = binarySearch(tiket, n, target);

    if (posisi != -1)
        printf("Tiket ditemukan pada posisi ke-%d (indeks ke-%d).\n", posisi + 1, posisi);
    else
        printf("Tiket tidak ditemukan dalam data.\n");
    return 0;
}