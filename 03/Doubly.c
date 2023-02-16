#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//============================Doubly==========================//

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertBeg(struct Node **head, int x)
{
    struct Node *curr = (*head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = (*head);
    // newNode->next=curr;

    (*head)->prev = newNode;
    // curr->prev=newNode;

    (*head) = newNode;
}

void insertEnd(struct Node **head, int x)
{
    struct Node *curr = (*head);
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newNode;

    newNode->prev = curr;
    newNode->data = x;
    newNode->next = NULL;
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
    newNode->prev = curr;

    curr->next->prev = newNode;
    curr->next = newNode;
}

void deleteBig(struct Node **head)
{
    struct Node *curr = (*head)->next;
    struct Node *temp = (*head);

    curr->prev = NULL;
    temp->next = NULL;
    (*head) = curr;
    free(temp);
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
    temp->prev = NULL;
    free(temp);
}

void deleteMid(struct Node **head, int pos)
{
    struct Node *curr = (*head);
    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }

    struct Node *temp = curr->next;

    temp->next->prev = curr;
    curr->next = curr->next->next;
    free(temp);
}





void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
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
    head->prev = NULL;

    one->data = 1;
    one->next = two;
    one->prev = head;

    two->data = 2;
    two->next = three;
    two->prev = one;

    three->data = 3;
    three->next = four;
    three->prev = two;

    four->data = 4;
    four->next = NULL;
    four->prev = three;

    printList(head);

    printf("\n==========Insert======================\n");

    insertBeg(&head, -1);
    printList(head);

    insertMid(&head, 20, 2);
    printList(head);


    insertEnd(&head, 5);
    printList(head);

    printf("\n==========Delete======================\n");

    deleteBig(&head);
    printList(head);

    //deleteMid(&head,3);
    //printList(head);

  //  deleteEnd(&head);
 //   printList(head);

    return 0;
}
