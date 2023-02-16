#include <stdio.h>
#include <stdlib.h>

int size, queue[100];
int front = -1, rear = -1;

void enqueue()
{
    int item;

    if (rear == size - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        printf("\nInset the element in queue : ");
        scanf("%d", &item);

        rear = rear + 1;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Enter the size of Queue.. ");
    scanf("%d", &size);

    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
    return 0;
}