#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int Data[MAX];

int SequentialSearch(int x, int *jumlah_perbandingan)
{
    printf("\nTracking per-Iterasi\n");
    for (int i = 0; i < MAX; i++)
    {
        (*jumlah_perbandingan)++;
        bool is_match = (Data[i] == x);

        printf("step %d: Membandingkan Kunci = %d, dengan Data[%d] = %d. Hasil: %s\n",
               *jumlah_perbandingan, x, i, Data[i], is_match ? "true" : "false");

        if (is_match)
            return i;
    }
    printf("Data tidak ditemukan.\n");
    return -1;
}

int main()
{
    srand(0);
    printf("DATA : ");
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 50 + 1;
        printf("%d ", Data[i]);
    }
    printf("\n\n");

    int Kunci;
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &Kunci);

    int hitung_seq = 0;
    int indeksKetemu = SequentialSearch(Kunci, &hitung_seq);

    printf("\nHasil Akhir Sequential Search\n");
    if (indeksKetemu != -1)
        printf("Data %d ditemukan pada indeks ke-%d.\n", Kunci, indeksKetemu);
    else
        printf("Data %d tidak ditemukan.\n", Kunci);
    printf("Total: %d kali iterasi/perbandingan.\n", hitung_seq);

    return 0;
}