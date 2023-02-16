#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void Enqueue(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void Dequeue()
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
}

void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void main()
{
    int choice = 0, item;

    printf("Implement Queue using LinkedList \n");

    while (choice != 7)
    {
        printf("\n Choose one of the following list");
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("\n enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("enter the item to be inserted ");
            scanf("%d", &item);
            Enqueue(&head, item);
        }
        break;
        case 2:
            Dequeue();
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("please enter valid choice.... ");
        }
    }
}
