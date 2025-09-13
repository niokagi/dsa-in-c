#include <stdio.h>
#include <stdlib.h>

#define MAKS_MOBIL 10
int tempat_parkir[MAKS_MOBIL];
int jumlah_mobil = 0;

void tampilkanPesan(const char *pesan)
{
    printf("%s\n", pesan);
}

void tampilkanParkiran()
{
    if (jumlah_mobil == 0)
    {
        tampilkanPesan("Tidak ada mobil di parkiran.");
        return;
    }
    printf("\nStatus parkiran: ");
    for (int i = 0; i < jumlah_mobil; i++)
    {
        printf("%d ", tempat_parkir[i]);
    }
    printf("\n");
}

void tambahMobil()
{
    if (jumlah_mobil == MAKS_MOBIL)
    {
        tampilkanPesan("Parkiran sudah penuh!");
        return;
    }
    int no_mobil;
    printf("\nMasukkan nomor mobil: ");
    scanf("%d", &no_mobil);
    tempat_parkir[jumlah_mobil] = no_mobil;
    jumlah_mobil++;

    char pesan[100];
    sprintf(pesan, "Mobil nomor %d berhasil ditambahkan ke parkiran.", no_mobil);
    tampilkanPesan(pesan);
}

void keluarkanMobilDepan()
{
    if (jumlah_mobil == 0)
    {
        tampilkanPesan("Parkiran kosong, tidak ada mobil yang bisa dikeluarkan!");
        return;
    }
    int no_keluar = tempat_parkir[0];

    char pesan[100];
    sprintf(pesan, "Mobil nomor %d telah keluar dari bagian depan.", no_keluar);
    tampilkanPesan(pesan);

    for (int i = 0; i < jumlah_mobil - 1; i++)
    {
        tempat_parkir[i] = tempat_parkir[i + 1];
    }
    jumlah_mobil--;
}

void keluarkanMobilTengah()
{
    if (jumlah_mobil == 0)
    {
        tampilkanPesan("Parkiran kosong, tidak ada mobil yang bisa dikeluarkan!");
        return;
    }

    int no_dicari, posisi = -1;
    printf("\nMasukkan nomor mobil yang ingin dikeluarkan: ");
    scanf("%d", &no_dicari);

    for (int i = 0; i < jumlah_mobil; i++)
    {
        if (tempat_parkir[i] == no_dicari)
        {
            posisi = i;
            break;
        }
    }

    if (posisi == -1)
    {
        char pesan[100];
        sprintf(pesan, "Mobil nomor %d tidak ditemukan di parkiran!", no_dicari);
        tampilkanPesan(pesan);
        return;
    }

    if (posisi == 0)
    {
        keluarkanMobilDepan();
        return;
    }

    char pesan[150];
    sprintf(pesan, "Memindahkan mobil-mobil sebelum mobil nomor %d ke area sementara...", no_dicari);
    tampilkanPesan(pesan);

    int area_sementara[MAKS_MOBIL];
    int jml_sementara = posisi;
    for (int i = 0; i < posisi; i++)
    {
        area_sementara[i] = tempat_parkir[i];
    }

    sprintf(pesan, "Mengeluarkan mobil nomor %d...", no_dicari);
    tampilkanPesan(pesan);

    for (int i = posisi; i < jumlah_mobil - 1; i++)
    {
        tempat_parkir[i] = tempat_parkir[i + 1];
    }
    jumlah_mobil--;

    sprintf(pesan, "Mengembalikan mobil dari area sementara ke parkiran...");
    tampilkanPesan(pesan);

    int sisa_mobil = jumlah_mobil - posisi;
    int mobil_sisa[MAKS_MOBIL];
    for (int i = 0; i < sisa_mobil; i++)
    {
        mobil_sisa[i] = tempat_parkir[posisi + i];
    }

    int urutan_baru[MAKS_MOBIL];
    int indeks = 0;
    for (int i = 0; i < jml_sementara; i++)
    {
        urutan_baru[indeks++] = area_sementara[i];
    }
    for (int i = 0; i < sisa_mobil; i++)
    {
        urutan_baru[indeks++] = mobil_sisa[i];
    }

    for (int i = 0; i < indeks; i++)
    {
        tempat_parkir[i] = urutan_baru[i];
    }

    jumlah_mobil = indeks;

    sprintf(pesan, "Mobil nomor %d telah berhasil dikeluarkan.", no_dicari);
    tampilkanPesan(pesan);
}

int main()
{
    int pilihan;
    do
    {
        printf("\nSISTEM PARKIR MOBIL\n");
        printf("1. Tambah Mobil\n");
        printf("2. Keluarkan Mobil dari Depan\n");
        printf("3. Keluarkan Mobil dari Tengah\n");
        printf("4. Tampilkan Status Parkiran\n");
        printf("5. Keluar Program\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahMobil();
            break;
        case 2:
            keluarkanMobilDepan();
            break;
        case 3:
            keluarkanMobilTengah();
            break;
        case 4:
            tampilkanParkiran();
            break;
        case 5:
            tampilkanPesan("Program selesai. Terima kasih.");
            break;
        default:
            tampilkanPesan("Pilihan tidak valid, silakan coba lagi!");
        }
    } while (pilihan != 5);

    return 0;
}
