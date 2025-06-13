#include <stdio.h>

int sequentialSearch(int arr[], int n, int kunci)
{
    printf("#Track per-iterasi\n");
    for (int i = 0; i < n; i++)
    {
        printf("Iterasi ke-%d: Membandingkan arr[%d] (%d) dengan kunci (%d) ", i + 1, i, arr[i], kunci);

        if (arr[i] == kunci)
        {
            printf("Ketemu/Cocok!\n");
            return i;
        }
        printf("Bukan.\n");
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
    int kunci = 1110;

    printf("Data Tiket: ");
    cetakArray(tiket, n);
    printf("Kunci yang dicari: %d\n\n", kunci);

    int posisi = sequentialSearch(tiket, n, kunci);

    if (posisi != -1)
        printf("\nTiket ditemukan pada posisi ke-%d (indeks ke-%d).\n", posisi + 1, posisi);
    else
        printf("\nTiket tidak ditemukan dalam data.\n");

    return 0;
}