#include <stdio.h>

int main()
{
    int n, low, high, mid;
    char jawaban;

    printf("==================================\n");
    printf("     Game Tebak Angka\n");
    printf("==================================\n");

    printf("Masukkan angka maksimum (n): ");
    scanf("%d", &n);
    printf("\nPikirkan sebuah angka antara 1 dan %d.\n", n);
    printf("Saya akan mencoba menebaknya.\nJawab dengan 'y' untuk ya dan 't' untuk tidak.\n\n");

    low = 1;
    high = n;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        printf("Apakah angka Anda lebih kecil dari %d? (y/t): ", mid + 1);
        scanf(" %c", &jawaban);

        if (jawaban == 'y' || jawaban == 'Y')
            high = mid;
        else
            low = mid + 1;
    }

    printf("\n----------------------------------\n");
    printf("Angka yang Anda pikirkan pasti %d!\n", low);
    printf("----------------------------------\n");

    return 0;
}