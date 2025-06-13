#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_PEGAWAI 20

typedef struct
{
    int nip;
    char nama[50];
} Pegawai;

Pegawai dataPegawai[MAX_PEGAWAI];
int jumlahPegawai = 0;
bool sudahTerurut = false;

int stricmp_custom(const char *s1, const char *s2)
{
    while (*s1)
    {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2))
            break;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

void printData()
{
    if (jumlahPegawai == 0)
    {
        printf("Belum ada data pegawai.\n");
        return;
    }
    printf("\nNo. | NIP      | Nama\n");
    printf("--------------------------------\n");
    for (int i = 0; i < jumlahPegawai; i++)
    {
        printf("%-3d | %-8d | %s\n", i + 1, dataPegawai[i].nip, dataPegawai[i].nama);
    }
    printf("--------------------------------\n");
}

void tukar(Pegawai *a, Pegawai *b)
{
    Pegawai temp = *a;
    *a = *b;
    *b = temp;
}

void quickSortNIP(int L, int R)
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
    quickSortNIP(L, j);
    quickSortNIP(i, R);
}

int sequentialSearchByNIP(int nip)
{
    for (int i = 0; i < jumlahPegawai; i++)
    {
        if (dataPegawai[i].nip == nip)
            return i;
    }
    return -1;
}

int sequentialSearchByName(char namaCari[])
{
    for (int i = 0; i < jumlahPegawai; i++)
    {
        if (stricmp_custom(dataPegawai[i].nama, namaCari) == 0)
            return i;
    }
    return -1;
}

int binarySearchByNIP(int nip)
{
    if (!sudahTerurut)
    {
        printf("PERINGATAN: Data belum diurutkan. Binary search mungkin gagal.\n");
        printf("Silakan pilih menu 'Urutkan Data' terlebih dahulu.\n");
        return -1;
    }
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

void geserKanan(int dariIndeks)
{
    for (int i = jumlahPegawai; i > dariIndeks; i--)
        dataPegawai[i] = dataPegawai[i - 1];
}
void geserKiri(int dariIndeks)
{
    for (int i = dariIndeks; i < jumlahPegawai - 1; i++)
        dataPegawai[i] = dataPegawai[i + 1];
}

void sisipData()
{
    if (jumlahPegawai >= MAX_PEGAWAI)
    {
        printf("Gagal: Array data pegawai sudah penuh.\n");
        return;
    }
    Pegawai pgwBaru;
    int nipKunci, pilihan, indeksKunci;
    printf("Masukkan NIP pegawai baru: ");
    scanf("%d", &pgwBaru.nip);
    printf("Masukkan Nama pegawai baru: ");
    scanf(" %[^\n]", pgwBaru.nama);
    printf("Masukkan NIP data kunci (tempat data akan disisipkan): ");
    scanf("%d", &nipKunci);
    indeksKunci = sequentialSearchByNIP(nipKunci);
    if (indeksKunci == -1)
    {
        printf("Gagal: NIP kunci %d tidak ditemukan.\n", nipKunci);
        return;
    }
    printf("1. Sisip SEBELUM data kunci\n2. Sisip SESUDAH data kunci\nPilih opsi: ");
    scanf("%d", &pilihan);
    if (pilihan == 1)
    {
        geserKanan(indeksKunci);
        dataPegawai[indeksKunci] = pgwBaru;
    }
    else if (pilihan == 2)
    {
        geserKanan(indeksKunci + 1);
        dataPegawai[indeksKunci + 1] = pgwBaru;
    }
    else
    {
        printf("Pilihan tidak valid.\n");
        return;
    }
    jumlahPegawai++;
    sudahTerurut = false;
    printf("Berhasil menyisipkan data.\n");
}

void hapusData()
{
    if (jumlahPegawai == 0)
    {
        printf("Gagal: Tidak ada data untuk dihapus.\n");
        return;
    }
    int nipKunci, indeksKunci;
    printf("Masukkan NIP data yang akan dihapus: ");
    scanf("%d", &nipKunci);
    indeksKunci = sequentialSearchByNIP(nipKunci);
    if (indeksKunci == -1)
    {
        printf("Gagal: NIP %d tidak ditemukan.\n", nipKunci);
        return;
    }
    geserKiri(indeksKunci);
    jumlahPegawai--;
    printf("Data dengan NIP %d berhasil dihapus.\n", nipKunci);
}

void cariData()
{
    int pilihan, pilihanMetode, nipCari, indeksHasil = -1;
    char namaCari[50];
    printf("Cari berdasarkan:\n1. NIP\n2. Nama\n3. NIP dan Nama (Gabungan)\nPilih opsi: ");
    scanf("%d", &pilihan);
    printf("\nPilih metode pencarian:\n1. Sequential Search\n2. Binary Search (Hanya untuk pencarian NIP)\nPilih opsi: ");
    scanf("%d", &pilihanMetode);

    if (pilihan == 1)
    {
        printf("Masukkan NIP yang dicari: ");
        scanf("%d", &nipCari);
        if (pilihanMetode == 1)
            indeksHasil = sequentialSearchByNIP(nipCari);
        else
            indeksHasil = binarySearchByNIP(nipCari);
    }
    else if (pilihan == 2)
    {
        printf("Masukkan Nama yang dicari: ");
        scanf(" %[^\n]", namaCari);
        if (pilihanMetode == 2)
        {
            printf("Binary Search hanya didukung untuk NIP.\n");
            return;
        }
        indeksHasil = sequentialSearchByName(namaCari);
    }
    else if (pilihan == 3)
    {
        printf("Masukkan NIP yang dicari: ");
        scanf("%d", &nipCari);
        printf("Masukkan Nama yang dicari: ");
        scanf(" %[^\n]", namaCari);
        if (pilihanMetode == 1)
            indeksHasil = sequentialSearchByNIP(nipCari);
        else
            indeksHasil = binarySearchByNIP(nipCari);

        if (indeksHasil != -1 && stricmp_custom(dataPegawai[indeksHasil].nama, namaCari) != 0)
            indeksHasil = -1;
    }

    if (indeksHasil != -1)
    {
        printf("\nData DITEMUKAN pada indeks ke-%d:\n", indeksHasil);
        printf("NIP  : %d\n", dataPegawai[indeksHasil].nip);
        printf("Nama : %s\n", dataPegawai[indeksHasil].nama);
    }
    else
        printf("\nData TIDAK DITEMUKAN.\n");
}

int main()
{
    dataPegawai[0] = (Pegawai){111, "Adhim"};
    dataPegawai[1] = (Pegawai){222, "Ludwig"};
    dataPegawai[2] = (Pegawai){333, "Chris"};
    dataPegawai[3] = (Pegawai){444, "Adolf"};
    dataPegawai[4] = (Pegawai){555, "Niokagi"};
    jumlahPegawai = 5;
    int pilihan = 0;
    while (pilihan != 6)
    {
        printf("\n========= Menu =========\n");
        printf("1. Tampilkan Semua Data\n2. Cari Data Pegawai\n3. Sisip Data Pegawai\n4. Hapus Data Pegawai\n5. Urutkan Data (berdasarkan NIP)\n6. Keluar\n");
        printf("\nPilih opsi menu: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            printData();
            break;
        case 2:
            cariData();
            break;
        case 3:
            sisipData();
            break;
        case 4:
            hapusData();
            break;
        case 5:
            quickSortNIP(0, jumlahPegawai - 1);
            sudahTerurut = true;
            printf("Data telah berhasil diurutkan berdasarkan NIP.\n");
            printData();
            break;
        case 6:
            printf("Terima kasih! Program berakhir.\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
    return 0;
}