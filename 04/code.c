#include <stdio.h>
#include <stdlib.h>

int n, top = -1, stack[100];

void push()
{
    int x;

    if (top == n)
    {
        printf("\n Overflow\n");
    }
    else
    {
        printf("\nEnter element to be inserted to the stack: ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n Underflow\n");
    }
    else
    {
        top = top - 1;
    }
}
void display()
{
    if (top == -1)
    {
        printf("\n Stack is empty \n");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    printf("Enter the size of stack.. ");
    scanf("%d", &n);

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
}
