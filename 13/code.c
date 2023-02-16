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

int main()
{

  struct Node *root = createNode(1);
  struct Node *leftChild = createNode(2);
  struct Node *rightChild = createNode(3);

  root->left = leftChild;
  root->right = rightChild;

  return 0;
}
