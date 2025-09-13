#include <stdio.h>
#include <string.h>
#define BESAR 100

typedef struct
{
    char kd[10];
    char nm[50];
    int sk;
} ent;

ent kumpulan[BESAR];
int jumlah = 0;

void tambah(ent entri)
{
    if (jumlah < BESAR)
    {
        kumpulan[jumlah] = entri;
        jumlah++;
    }
    else
    {
        printf("Maaf, ruang penyimpanan sudah penuh!\n");
    }
}

ent keluarkan()
{
    if (jumlah == 0)
    {
        ent kosong;
        strcpy(kosong.kd, "");
        strcpy(kosong.nm, "");
        kosong.sk = -1;
        return kosong;
    }

    int im = 0;
    for (int j = 1; j < jumlah; j++)
    {
        if (kumpulan[j].sk > kumpulan[im].sk)
        {
            im = j;
        }
    }

    ent terbaik = kumpulan[im];

    for (int j = im; j < jumlah - 1; j++)
    {
        kumpulan[j] = kumpulan[j + 1];
    }
    jumlah--;

    return terbaik;
}

int main()
{
    ent temp;

    strcpy(temp.kd, "01");
    strcpy(temp.nm, "Andi");
    temp.sk = 90;
    tambah(temp);

    strcpy(temp.kd, "02");
    strcpy(temp.nm, "Budi");
    temp.sk = 70;
    tambah(temp);

    strcpy(temp.kd, "03");
    strcpy(temp.nm, "Candra");
    temp.sk = 85;
    tambah(temp);

    ent hasil = keluarkan();
    printf("Keluaran: %s | %s | %d\n", hasil.kd, hasil.nm, hasil.sk);

    strcpy(temp.kd, "04");
    strcpy(temp.nm, "Didi");
    temp.sk = 80;
    tambah(temp);

    strcpy(temp.kd, "05");
    strcpy(temp.nm, "Edi");
    temp.sk = 95;
    tambah(temp);

    hasil = keluarkan();
    printf("Keluaran: %s | %s | %d\n", hasil.kd, hasil.nm, hasil.sk);

    hasil = keluarkan();
    printf("Keluaran: %s | %s | %d\n", hasil.kd, hasil.nm, hasil.sk);

    strcpy(temp.kd, "06");
    strcpy(temp.nm, "Fanda");
    temp.sk = 75;
    tambah(temp);

    printf("\nIsi data antrian saat ini:\n");
    for (int j = 0; j < jumlah; j++)
    {
        printf("%s | %s | %d\n", kumpulan[j].kd, kumpulan[j].nm, kumpulan[j].sk);
    }

    return 0;
}
