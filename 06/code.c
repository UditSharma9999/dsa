#include <stdio.h>
#include <stdlib.h>

int size, queue[100];
int front = -1, rear = -1;

int isFull()
{
    if (front == rear + 1 || (front == 0 && rear == size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    int item;

    if (isFull())
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("\nInset the element in queue : ");
        scanf("%d", &item);

        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        if (front == rear)
        {
            front, rear = -1, -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}

void display()
{
    if (isFull())
    {
        printf("Queue is Empty \n");
    }
    else
    {
        int i;
        for (i = front; i < rear; i = (i + 1) % size)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Enter the size of Circular Queue.. ");
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