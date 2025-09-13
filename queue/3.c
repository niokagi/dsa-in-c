#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int parking[MAX];
int count = 0;

void printMessage(const char *message)
{
    printf("\n====================\n%s\n====================\n", message);
}

void displayParking()
{
    if (count == 0)
    {
        printMessage("Parkir kosong.");
        return;
    }
    printf("\n====================\nKondisi parkir: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", parking[i]);
    }
    printf("\n====================\n");
}

void mobilMasuk()
{
    if (count == MAX)
    {
        printMessage("Parkir Penuh!");
        return;
    }
    int nomor;
    printf("\n====================\nMasukkan nomor mobil: ");
    scanf("%d", &nomor);
    parking[count] = nomor;
    count++;

    char pesan[100];
    sprintf(pesan, "Mobil dengan nomor %d masuk ke parkir.", nomor);
    printMessage(pesan);
}

void mobilKeluarDepan()
{
    if (count == 0)
    {
        printMessage("Parkir kosong, tidak ada mobil yang bisa keluar!");
        return;
    }
    int keluar = parking[0];

    char pesan[100];
    sprintf(pesan, "Mobil dengan nomor %d keluar dari depan.", keluar);
    printMessage(pesan);

    for (int i = 0; i < count - 1; i++)
    {
        parking[i] = parking[i + 1];
    }
    count--;
}

void mobilKeluarTengah()
{
    if (count == 0)
    {
        printMessage("Parkir kosong, tidak ada mobil yang bisa keluar!");
        return;
    }

    int nomor, pos = -1;
    printf("\n====================\nMasukkan nomor mobil yang akan keluar: ");
    scanf("%d", &nomor);

    for (int i = 0; i < count; i++)
    {
        if (parking[i] == nomor)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        char pesan[100];
        sprintf(pesan, "Mobil dengan nomor %d tidak ditemukan!", nomor);
        printMessage(pesan);
        return;
    }

    if (pos == 0)
    {
        mobilKeluarDepan();
        return;
    }

    char pesan[150];
    sprintf(pesan, "Memindahkan mobil-mobil di depan mobil nomor %d ke area penampungan sementara...", nomor);
    printMessage(pesan);

    int temp[MAX];
    int tempCount = pos;
    for (int i = 0; i < pos; i++)
    {
        temp[i] = parking[i];
    }

    sprintf(pesan, "Mengeluarkan mobil dengan nomor %d...", nomor);
    printMessage(pesan);

    for (int i = pos; i < count - 1; i++)
    {
        parking[i] = parking[i + 1];
    }
    count--;

    sprintf(pesan, "Mengembalikan mobil dari area penampungan sementara...");
    printMessage(pesan);

    int remainingCount = count - pos;
    int remaining[MAX];
    for (int i = 0; i < remainingCount; i++)
    {
        remaining[i] = parking[pos + i];
    }

    int newOrder[MAX];
    int index = 0;
    for (int i = 0; i < tempCount; i++)
    {
        newOrder[index++] = temp[i];
    }
    for (int i = 0; i < remainingCount; i++)
    {
        newOrder[index++] = remaining[i];
    }

    for (int i = 0; i < index; i++)
    {
        parking[i] = newOrder[i];
    }

    count = index;

    sprintf(pesan, "Mobil dengan nomor %d telah keluar.", nomor);
    printMessage(pesan);
}

int main()
{
    int choice;
    do
    {
        printf("\n===== SIMULASI TEMPAT PARKIR =====\n");
        printf("1. Mobil Masuk\n");
        printf("2. Mobil Paling Depan Keluar\n");
        printf("3. Mobil Tengah Keluar\n");
        printf("4. Tampilkan kondisi parkir\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            mobilMasuk();
            break;
        case 2:
            mobilKeluarDepan();
            break;
        case 3:
            mobilKeluarTengah();
            break;
        case 4:
            displayParking();
            break;
        case 5:
            printMessage("Keluar dari program.");
            break;
        default:
            printMessage("Pilihan tidak valid!");
        }
    } while (choice != 5);

    return 0;
}
