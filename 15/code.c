#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

void inorder(struct Node* head)
{
    if (head == NULL)
        return;

    inorder(head->left);
    printf("%d ", head->data);
    inorder(head->right);
}

int main()
{
    struct Node *root = createNode(50);
    struct Node *n1 = createNode(30);
    struct Node *n2 = createNode(70);
    struct Node *n3 = createNode(10);
    struct Node *n4 = createNode(35);
    struct Node *n5 = createNode(60);
    struct Node *n6 = createNode(80);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    inorder(root);

    return 0;
}
