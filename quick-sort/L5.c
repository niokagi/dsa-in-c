#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 500000

enum{
    false,
    true
};

static inline void swap_int(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef enum{
    ASCENDING = 0,
    DESCENDING = 1
} Order;

void insertionSort(int arr[], int n, int desc){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((desc && arr[j] < key) || (!desc && arr[j] > key)))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int desc){
    for (int i = 0; i < n - 1; i++){
        int idx = i;
        for (int j = i + 1; j < n; j++){
            if ((desc && arr[j] > arr[idx]) || (!desc && arr[j] < arr[idx]))
                idx = j;
        }
        swap_int(&arr[i], &arr[idx]);
    }
}

void bubbleSort(int arr[], int n, int desc){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if ((desc && arr[j] < arr[j + 1]) || (!desc && arr[j] > arr[j + 1]))
                swap_int(&arr[j], &arr[j + 1]);
        }
    }
}

void bubbleSortFlag(int arr[], int n, int desc){
    for (int i = 0; i < n - 1; i++){
        int swapped = false;
        for (int j = 0; j < n - 1 - i; j++){
            if ((desc && arr[j] < arr[j + 1]) || (!desc && arr[j] > arr[j + 1]))
            {
                swap_int(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void shellSort(int arr[], int n, int desc){
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && ((desc && arr[j - gap] < temp) || (!desc && arr[j - gap] > temp)); j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partitionQS(int arr[], int low, int high, int desc){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if ((desc && arr[j] >= pivot) || (!desc && arr[j] <= pivot)){
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int desc){
    if (low < high){
        int pi = partitionQS(arr, low, high, desc);
        quickSort(arr, low, pi - 1, desc);
        quickSort(arr, pi + 1, high, desc);
    }
}

void merge(int arr[], int l, int m, int r, int desc){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    if (!L || !R){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if ((desc && L[i] >= R[j]) || (!desc && L[i] <= R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r, int desc){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, desc);
        mergeSort(arr, m + 1, r, desc);
        merge(arr, l, m, r, desc);
    }
}

int main(void){
    int n;
    printf("Masukkan jumlah elemen (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX){
        printf("Input tidak valid.\n");
        return EXIT_FAILURE;
    }

    int *arr = malloc(n * sizeof(int));
    int *data_copy = malloc(n * sizeof(int));
    if (!arr || !data_copy){
        fprintf(stderr, "Allocation error\n");
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand();

    int alg, order;
    printf("\nALGORITMA SORTING\n");
    printf("1. Insertion\n2. Selection\n3. Bubble\n4. Bubble dengan Flag\n5. Shell\n6. Quick\n7. Merge\n");
    printf("Pilihan algoritma: ");
    scanf("%d", &alg);
    printf("1. Ascending\n2. Descending\nPilihan urutan: ");
    scanf("%d", &order);
    int desc = (order == 2);

    memcpy(data_copy, arr, n * sizeof(int));
    clock_t start = clock();
    switch (alg){
        case 1:
            insertionSort(data_copy, n, desc);
            break;
        case 2:
            selectionSort(data_copy, n, desc);
            break;
        case 3:
            bubbleSort(data_copy, n, desc);
            break;
        case 4:
            bubbleSortFlag(data_copy, n, desc);
            break;
        case 5:
            shellSort(data_copy, n, desc);
            break;
        case 6:
            quickSort(data_copy, 0, n - 1, desc);
            break;
        case 7:
            mergeSort(data_copy, 0, n - 1, desc);
            break;
        default:
            printf("Pilihan algoritma tidak valid.\n");
            free(arr);
            free(data_copy);
            return EXIT_FAILURE;
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Waktu: %.3f detik\n", time_spent);

    free(arr);
    free(data_copy);
    return 0;
}
