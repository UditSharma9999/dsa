#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// ==============================circularly Singly ====================//
struct Node
{
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int x)
{
    struct Node *curr = (*head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    do
    {
        curr = curr->next;
    } while (curr->next != (*head));

    newNode->data = x;
    newNode->next = curr->next;
    curr->next = newNode;
}

void insertBeg(struct Node **head, int x)
{
    struct Node *curr = *(head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    do
    {
        curr = curr->next;
    } while (curr->next != (*head));

    newNode->data = x;
    newNode->next = (*head);
    curr->next = newNode;

    (*head) = newNode;
}

void insertMid(struct Node **head, int x, int pos)
{
    struct Node *curr = (*head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    for (int i = 1; i < pos; i++)
    {
        curr = curr->next;
    }

    newNode->data = x;
    newNode->next = curr->next;
    curr->next = newNode;
}




void deleteBeg(struct Node **head)
{
    struct Node *curr = (*head);

    do
    {
        curr = curr->next;
    } while (curr->next != (*head));

    struct Node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    (*head) = curr->next;
}

void deleteEnd(struct Node **head)
{
    struct Node *curr = (*head);
    do
    {
        curr = curr->next;
    } while (curr->next->next != (*head));

    struct Node *tail = curr->next;
    curr->next = curr->next->next;
    free(tail);
}

void deleteMid(struct Node **head, int pos)
{
    struct Node *curr = (*head);

    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }

    struct Node *temp = curr->next;

    curr->next = temp->next;
    free(temp);
}




void printList(struct Node **head)
{
    struct Node *curr = (*head);

    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != (*head));

    printf("\n");
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
    four->next = head;

    printList(&head);

    printf("\n==========Insert======================\n");

    insertEnd(&head, 5);
    printList(&head);

    insertBeg(&head, -1);
    printList(&head);

    insertMid(&head, 10, 2);
    printList(&head);

    printf("\n==========Delete======================\n");

    //deleteBeg(&head);
    //printList(&head);

  //  deleteMid(&head,3);
//   printList(&head);

   deleteEnd(&head);
   printList(&head);

    return 0;
}
