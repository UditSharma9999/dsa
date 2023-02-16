#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push()
{
    int value;
    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter element to be inserted to the stack: ");
    scanf("%d", &value);

    newNode->data = value;

    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("\n Underflow\n");
    }
    else
    {
        struct Node *curr = top;
        top = top->next;
        free(curr);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("\n Underflow\n");
    }
    else
    {
        struct Node *temp = top;

        while (temp != NULL)
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    printf("Stack using LinkedList... \n ");

    while (1)
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!! ");
        }
    }

    return 0;
}
