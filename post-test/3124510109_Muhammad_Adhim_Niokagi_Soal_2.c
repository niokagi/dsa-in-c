#include <stdio.h>

void Sort(int arr[], int n)
{
    int i, j, indeksMaks;

    for (i = 0; i < n - 1; i++)
    {
        indeksMaks = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[indeksMaks])
                indeksMaks = j;
        }

        if (indeksMaks != i)
        {
            int temp = arr[indeksMaks];
            arr[indeksMaks] = arr[i];
            arr[i] = temp;
        }
    }
}

void cetakArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int nilai[] = {75, 60, 85, 90, 45, 70, 55, 95, 93, 88};
    int n = sizeof(nilai) / sizeof(nilai[0]);

    printf("\nRank Nilai Ujian Mahasiswa\n");
    printf("Metode yang digunakan: Selection Sort\n(NRP 3124510109 modulo 4 = 1)\n\n");

    // sblm urut
    printf("Data Nilai Sebelum Diurutkan:\n");
    cetakArray(nilai, n);
    printf("\n");

    Sort(nilai, n);

    // sesudah diurut
    printf("Data Nilai Sesudah Diurutkan (dari terbesar):\n");
    cetakArray(nilai, n);
    printf("\n");

    printf("3 Nilai Teratas (Mhs Penerima Beasiswa):\n");
    printf("1. Rank 1: %d\n", nilai[0]);
    printf("2. Rank 2: %d\n", nilai[1]);
    printf("3. Rank 3: %d\n", nilai[2]);

    return 0;
}