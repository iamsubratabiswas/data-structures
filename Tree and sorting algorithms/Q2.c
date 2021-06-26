/*
Write a program to create a binary tree from its pre-order and in-order traversal.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{

    struct node *Node = (struct node *)malloc(sizeof(struct node));

    Node->data = data;

    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void inorder(struct node *Node)
{
    if (Node != NULL)
    {
        inorder(Node->left);
        printf("%d ", Node->data);
        
        inorder(Node->right);
    }
}

int preIndex = 0;

struct node *NewTree(int pre[], int in[], int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    struct node *root = newNode(pre[preIndex++]);

    int i;
    for (i = inStart; i <= inEnd; i++)
    {
        if (in[i] == root->data)
            break;
    }
    root->left = NewTree(pre, in, inStart, i - 1);
    root->right = NewTree(pre, in, i + 1, inEnd);

    return root;
}

int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    int pre[n], in[n];

    printf("Enter pre-order traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }

    printf("Enter in-order traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }

    struct node* root =NewTree(pre,in,0,n-1);
    printf("Contructed Tree: \n");
    inorder(root);

    free(root);
    root = NULL;

}