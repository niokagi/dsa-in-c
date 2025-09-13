#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char nrp[10];
    char nama[50];
    int nilai;
} Mahasiswa;

Mahasiswa pq[MAX];
int size = 0;

void push(Mahasiswa m)
{
    if (size < MAX)
    {
        pq[size] = m;
        size++;
    }
    else
    {
        printf("Queue penuh!\n");
    }
}

Mahasiswa pop()
{
    if (size == 0)
    {
        Mahasiswa kosong;
        strcpy(kosong.nrp, "");
        strcpy(kosong.nama, "");
        kosong.nilai = -1;
        return kosong;
    }

    int idxMax = 0;
    int i;
    for (i = 1; i < size; i++)
    {
        if (pq[i].nilai > pq[idxMax].nilai)
        {
            idxMax = i;
        }
    }

    Mahasiswa highest = pq[idxMax];

    for (i = idxMax; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }
    size--;

    return highest;
}

int main()
{
    Mahasiswa m;

    strcpy(m.nrp, "01");
    strcpy(m.nama, "Andi");
    m.nilai = 90;
    push(m);

    strcpy(m.nrp, "02");
    strcpy(m.nama, "Budi");
    m.nilai = 70;
    push(m);

    strcpy(m.nrp, "03");
    strcpy(m.nama, "Candra");
    m.nilai = 85;
    push(m);

    Mahasiswa keluar = pop();
    printf("Pop -> %s %s %d\n", keluar.nrp, keluar.nama, keluar.nilai);

    strcpy(m.nrp, "04");
    strcpy(m.nama, "Didi");
    m.nilai = 80;
    push(m);

    strcpy(m.nrp, "05");
    strcpy(m.nama, "Edi");
    m.nilai = 95;
    push(m);

    keluar = pop();
    printf("Pop -> %s %s %d\n", keluar.nrp, keluar.nama, keluar.nilai);

    keluar = pop();
    printf("Pop -> %s %s %d\n", keluar.nrp, keluar.nama, keluar.nilai);

    strcpy(m.nrp, "06");
    strcpy(m.nama, "Fanda");
    m.nilai = 75;
    push(m);

    printf("\nData di dalam Priority Queue saat ini:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s %s %d\n", pq[i].nrp, pq[i].nama, pq[i].nilai);
    }

    return 0;
}
