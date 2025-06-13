#include <stdio.h>

// proto
int maksPengunjung(int arr[], int n);

int main()
{
    int pengunjung[] = {12, 20, 15, 30, 18, 25, 10, 22};
    int n = 8;

    int idxJamTerbanyak = maksPengunjung(pengunjung, n);
    int jmlTerbanyak = pengunjung[idxJamTerbanyak];

    printf("Jumlah pengunjung terbanyak ada sebanyak: %d orang.\n", jmlTerbanyak);
    printf("Terjadi pada jam ke %d.\n", idxJamTerbanyak + 1);

    return 0;
}

int maksPengunjung(int arr[], int n)
{
    if (n == 1)
        return 0;
    // turun sampai idx ke-1
    int idxTerakhir = maksPengunjung(arr, n - 1);
    // kemudian naik dan membandingkan index lama dg index baru
    if (arr[n - 1] > arr[idxTerakhir])
        return n - 1;
    else
        return idxTerakhir;
}