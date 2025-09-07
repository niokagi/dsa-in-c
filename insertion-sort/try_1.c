#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void main()
{
    int data_awal[MAX], data_urut[MAX];
    int i;

    printf("Sebelum pengurutan : \n");
    for (i = 0; i < MAX; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf("%d ", data_awal[i]);
    }

    printf("\n");
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
}
