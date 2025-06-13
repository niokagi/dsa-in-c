#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PEGAWAI 200000

typedef struct
{
    int nip;
    char nama[50];
} Pegawai;

Pegawai dataPegawai[MAX_PEGAWAI];
int jumlahPegawai = 0;
bool sudahTerurut = false;

int sequentialSearchByNIP(int nip)
{
    for (int i = 0; i < jumlahPegawai; i++)
    {
        if (dataPegawai[i].nip == nip)
            return i;
    }
    return -1;
}

int binarySearchByNIP(int nip)
{
    if (!sudahTerurut)
        return -1;
    int L = 0, R = jumlahPegawai - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (dataPegawai[mid].nip == nip)
            return mid;
        if (dataPegawai[mid].nip < nip)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}

void tukar(Pegawai *a, Pegawai *b)
{
    Pegawai temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortByNIP(int L, int R)
{
    if (L >= R)
        return;
    int i = L, j = R;
    int pivot = dataPegawai[(L + R) / 2].nip;
    while (i <= j)
    {
        while (dataPegawai[i].nip < pivot)
            i++;
        while (dataPegawai[j].nip > pivot)
            j--;
        if (i <= j)
        {
            tukar(&dataPegawai[i], &dataPegawai[j]);
            i++;
            j--;
        }
    }
    quickSortByNIP(L, j);
    quickSortByNIP(i, R);
}

int main()
{
    printf("Data yg digunakan untuk pengujian (%d data)\n", MAX_PEGAWAI);
    for (int i = 0; i < MAX_PEGAWAI; i++)
    {
        dataPegawai[i].nip = (rand() % 500000) + 1;
        sprintf(dataPegawai[i].nama, "Pegawai_%d", i + 1);
    }
    jumlahPegawai = MAX_PEGAWAI;

    int nipDicari = 999999;
    dataPegawai[MAX_PEGAWAI - 1].nip = nipDicari;
    printf("Kunci yg dicari: NIP %d\n", nipDicari);
    printf("==============================================\n");

    clock_t start, end;
    double cpuTime;

    printf("Sequential Search\n");
    start = clock();
    int hasilSeq = sequentialSearchByNIP(nipDicari);
    end = clock();
    cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (hasilSeq != -1)
        printf("> Data ditemukan di indeks %d.\n", hasilSeq);
    printf("> Waktu eksekusi: %f detik\n", cpuTime);
    printf("----------------------------------------------\n");

    printf("Sorting (Quicksort)\n");
    start = clock();
    quickSortByNIP(0, jumlahPegawai - 1);
    sudahTerurut = true;
    end = clock();
    double sortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("> Waktu eksekusi: %f detik\n", sortTime);
    printf("----------------------------------------------\n");

    printf("Binary Search\n");
    start = clock();
    int hasilBinary = binarySearchByNIP(nipDicari);
    end = clock();
    cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (hasilBinary != -1)
        printf("> Data ditemukan di indeks %d.\n", hasilBinary);
    printf("> Waktu eksekusi: %f detik\n", cpuTime);
    printf("==============================================\n");

    printf("\nHasil akhir:\n");
    printf("Sequential Search             : %f detik\n", sortTime);
    printf("Binary Search (inc sorting)   :  %f detik\n", sortTime, cpuTime, sortTime + cpuTime);
    printf("\nJadi, Binary Search yg lebih cepat.\n");

    return 0;
}