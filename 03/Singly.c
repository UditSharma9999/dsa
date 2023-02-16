#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertEnd(struct Node **head, int x)
{
    struct Node *temp = (*head);

    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBeg(struct Node **head, int x)
{
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = (*head);

    (*head) = newNode;
}

void insertMin(struct Node **head, int x, int pos)
{

    struct Node *temp = (*head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    newNode->data = x;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteEnd(struct Node **head)
{
    struct Node *curr = (*head);

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    struct Node *temp = curr->next;
    curr->next = NULL;
    free(temp);
}

void deleteBeg(struct Node **head)
{
    struct Node *curr = (*head);
    curr = curr->next;
    free((*head));
    (*head) = curr;
}

void deleteMid(struct Node **head, int pos)
{
    struct Node *curr = (*head);

    for (int i = 0; i < pos - 1; i++) // pos-2  for deleteing the Node;
    {
        curr = curr->next;
    }

    struct Node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;
    struct Node *four = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    one = (struct Node *)malloc(sizeof(struct Node));
    two = (struct Node *)malloc(sizeof(struct Node));
    three = (struct Node *)malloc(sizeof(struct Node));
    four = (struct Node *)malloc(sizeof(struct Node));

    head->data = 0;
    head->next = one;

    one->data = 1;
    one->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = four;

    four->data = 4;
    four->next = NULL;

    printList(head);

    printf("\n==========Insert======================\n");

    insertEnd(&head, 5);
    printList(head);

    insertMin(&head, 10, 2);
    printList(head);

    insertBeg(&head, -1);
    printList(head);

    printf("\n==========Delete======================\n");

    // deleteBeg(&head);
    // printList(head);

    deleteMid(&head, 3);
    printList(head);

    // deleteEnd(&head);
    // printList(head);

    return 0;
}
