#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Gagal alokasi memori");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertSorted(Node **headRef, int data)
{
    Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    Node *curr = *headRef;
    while (curr && curr->data < data)
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
}

void deleteNode(Node **headRef, int key)
{
    if (*headRef == NULL)
    {
        printf("List kosong, tidak ada yang dihapus.\n");
        return;
    }
    Node *curr = *headRef;
    while (curr && curr->data != key)
        curr = curr->next;
    if (!curr)
    {
        printf("Node dengan data %d tidak ditemukan.\n", key);
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
    printf("Node dengan data %d telah dihapus.\n", key);
}

void printList(Node *head)
{
    if (!head)
    {
        printf("List kosong.\n");
        return;
    }
    printf("Isi Doubly Linked List: ");
    for (Node *p = head; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

int main(void)
{
    Node *head = NULL;
    int choice, value;

    printf("=== Menu Doubly Linked List (int) ===\n");
    do
    {
        printf("\n1. Insert terurut\n");
        printf("2. Hapus node\n");
        printf("3. Print list\n");
        printf("0. Exit\n");
        printf("Pilihan: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Masukkan nilai untuk disisip: ");
            if (scanf("%d", &value) == 1)
            {
                insertSorted(&head, value);
                printf("-> %d berhasil disisipkan.\n", value);
            }
            break;
        case 2:
            printf("Masukkan nilai yang akan dihapus: ");
            if (scanf("%d", &value) == 1)
            {
                deleteNode(&head, value);
            }
            break;
        case 3:
            printList(head);
            break;
        case 0:
            printf("Keluar program.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
        while (getchar() != '\n')
            ;
    } while (choice != 0);
    while (head)
    {
        deleteNode(&head, head->data);
    }
    return 0;
}
