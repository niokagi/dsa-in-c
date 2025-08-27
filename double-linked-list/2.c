#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CLASS 20

typedef struct Node
{
    int nrp;
    char name[MAX_NAME];
    char kelas[MAX_CLASS];
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int nrp, const char *name, const char *kelas)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Gagal alokasi memori");
        exit(EXIT_FAILURE);
    }
    newNode->nrp = nrp;
    strncpy(newNode->name, name, MAX_NAME - 1);
    newNode->name[MAX_NAME - 1] = '\0';
    strncpy(newNode->kelas, kelas, MAX_CLASS - 1);
    newNode->kelas[MAX_CLASS - 1] = '\0';
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertSorted(Node **headRef, int nrp, const char *name, const char *kelas)
{
    Node *newNode = createNode(nrp, name, kelas);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    Node *curr = *headRef;
    while (curr && curr->nrp < nrp)
        curr = curr->next;
    if (curr == *headRef)
    {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
    else if (curr == NULL)
    {
        Node *tail = *headRef;
        while (tail->next)
            tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    }
    else
    {
        Node *prevNode = curr->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
    printf("-> Mahasiswa NRP %d berhasil disisip.\n", nrp);
}

void deleteNode(Node **headRef, int nrp)
{
    if (*headRef == NULL)
    {
        printf("List kosong, tidak ada yang dihapus.\n");
        return;
    }
    Node *curr = *headRef;
    while (curr && curr->nrp != nrp)
        curr = curr->next;
    if (!curr)
    {
        printf("NRP %d tidak ditemukan.\n", nrp);
        return;
    }
    if (curr == *headRef)
    {
        *headRef = curr->next;
        if (*headRef)
            (*headRef)->prev = NULL;
    }
    else
    {
        curr->prev->next = curr->next;
    }
    if (curr->next)
        curr->next->prev = curr->prev;
    free(curr);
    printf("-> Mahasiswa NRP %d telah dihapus.\n", nrp);
}

void updateNode(Node *head, int nrp)
{
    Node *curr = head;
    while (curr && curr->nrp != nrp)
        curr = curr->next;
    if (!curr)
    {
        printf("NRP %d tidak ditemukan.\n", nrp);
        return;
    }
    printf("Masukkan nama baru: ");
    fgets(curr->name, MAX_NAME, stdin);
    curr->name[strcspn(curr->name, "\n")] = '\0';
    printf("Masukkan kelas baru: ");
    fgets(curr->kelas, MAX_CLASS, stdin);
    curr->kelas[strcspn(curr->kelas, "\n")] = '\0';
    printf("-> Data NRP %d berhasil di-update.\n", nrp);
}

void printList(Node *head)
{
    if (!head)
    {
        printf("List kosong.\n");
        return;
    }
    printf("Daftar Mahasiswa:\n");
    printf("NRP\tNama\t\tKelas\n");
    printf("--------------------------------\n");
    for (Node *p = head; p; p = p->next)
    {
        printf("%d\t%-15s%s\n",
               p->nrp, p->name, p->kelas);
    }
}

int main(void)
{
    Node *head = NULL;
    int choice, nrp;

    do
    {
        printf("\n=== Menu Data Mahasiswa ===\n");
        printf("1. Insert terurut (NRP)\n");
        printf("2. Hapus (NRP)\n");
        printf("3. Update (NRP)\n");
        printf("4. Print list\n");
        printf("0. Exit\n");
        printf("Pilihan: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
        {
            char name[MAX_NAME];
            char kelas[MAX_CLASS];

            printf("Masukkan NRP: ");
            if (scanf("%d", &nrp) == 1)
            {
                while (getchar() != '\n')
                    ;
                printf("Masukkan Nama : ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Masukkan Kelas: ");
                fgets(kelas, MAX_CLASS, stdin);
                kelas[strcspn(kelas, "\n")] = '\0';

                insertSorted(&head, nrp, name, kelas);
            }
            break;
        }
        case 2:
            printf("Masukkan NRP yang akan dihapus: ");
            if (scanf("%d", &nrp) == 1)
            {
                while (getchar() != '\n')
                    ;
                deleteNode(&head, nrp);
            }
            break;
        case 3:
            printf("Masukkan NRP yang akan di-update: ");
            if (scanf("%d", &nrp) == 1)
            {
                while (getchar() != '\n')
                    ;
                updateNode(head, nrp);
            }
            break;
        case 4:
            printList(head);
            break;
        case 0:
            printf("Keluar program.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 0);

    while (head)
    {
        deleteNode(&head, head->nrp);
    }
    return 0;
}
