/*Write a menu driven program to do the following
a. Create a binary search tree.
b. Search a key in the binary search tree.
c. Find in-order predecessor and successor of a node whose key will be an user
input.
d. Insert a key in the binary search tree.
e. Delete a key from binary search tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

struct BSTnode *newNode(int val)
{
    struct BSTnode *node = (struct BSTnode *)malloc(sizeof(struct BSTnode));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

bool search(struct BSTnode *root, int key)
{
    if (root == NULL)
        return false;
    while (root != NULL)
    {
        if (root->data == key)
            return true;
        else if (key > root->data)
            root = root->right;
        else if (key < root->data)
            root = root->left;
    }

    return false;
}

struct BSTnode *insert(struct BSTnode *root, int key)
{
    struct BSTnode *temp = newNode(key);

    struct BSTnode *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (key > curr->data)
            curr = curr->right;
        else if (key < curr->data)
            curr = curr->left;
        else
            return root;
    }
    if (parent == NULL)
        return temp;
    else if (key > parent->data)
        parent->right = temp;
    else
        parent->left = temp;
    return root;
}

void inorder(struct BSTnode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct BSTnode *in_order_predecessor(struct BSTnode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            struct BSTnode *temp = root->left;
            while (temp->right)
                temp = temp->right;
            return temp;
        }
    }

    if (key < root->data)
        return in_order_predecessor(root->left, key);

    return in_order_predecessor(root->right, key);
}

struct BSTnode *in_order_successor(struct BSTnode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        if (root->right != NULL)
        {
            struct BSTnode *temp = root->right;
            while (temp->left)
                temp = temp->left;
            return temp;
        }
    }

    if (key < root->data)
        return in_order_successor(root->left, key);

    return in_order_successor(root->right, key);
}

struct BSTnode *FindMinRight(struct BSTnode *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct BSTnode *Delete(struct BSTnode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data > key)
        root->left = Delete(root->left, key);
    else if (root->data < key)
        root->right = Delete(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct BSTnode  *temp = root->right;
           free(root);
            root = NULL;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BSTnode *temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }
        else
        {
             struct BSTnode * succ = FindMinRight(root);
            root->data = succ->data;
            root->right = Delete(root->right, succ->data);
        }
    }
    return root;
}

int main()
{
    int ch = 0, N, Skey, Ikey, ele, val, del;
    struct BSTnode *root = NULL;
    while (1)
    {
        printf("\n1.Create a binary search tree\n2.Search a key in the binary search tree\n3.Find  in-order  predecessor  and  successor  of  a  node \n4.Insert a key in the binary search tree\n5.Delete a key from binary search tree\n6.Exit\n7.Print Binary search tree in inorder");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter no. of nodes Binary search tree: \n");
            scanf("%d", &N);

            printf("Enter %d Elements: \n", N);
            for (int i = 0; i < N; i++)
            {
                scanf("%d", &ele);
                root = insert(root, ele);
            }
            printf("Newly constructed inorder Binary Search Tree:\n");
            inorder(root);
            printf("\n");
            break;

        case 2:
            printf("\nEnter the element to search in the Binary search tree: \n");
            scanf("%d", &Skey);

            if (search(root, Skey))
                printf("%d is present in Binary search tree\n", Skey);
            else
                printf("%d is not present in Binary search tree\n", Skey);
            break;
        case 3:
            printf("\nEnter the node: \n");
            scanf("%d", &val);
            struct BSTnode *successor = in_order_successor(root, val);
            if (successor)
                printf("in-order successor: %d\n", successor->data);
            else
                printf("in-order successor doesn't exist\n");

            struct BSTnode *predecessor = in_order_predecessor(root, val);
            if (predecessor)
                printf("in-order predecessor: %d\n", predecessor->data);
            else
                printf("in-order predecessor doesn't exist\n");
            break;
        case 4:
            printf("\nEnter the key to insert in Binary search tree: \n");
            scanf("%d", &Ikey);
            if (search(root, Ikey))
                printf("%d is already present in Binary search tree.So cannot insert.\n", Ikey);
            else
            {
                root = insert(root, Ikey);
                printf("%d inserted \n", Ikey);
            }
            break;
        case 5:
            printf("\nEnter the key to delete from Binary search tree: \n");
            scanf("%d", &del);
            if (search(root, del) == false)
                printf("%d doesn't exist in Binary search tree.\n", del);
            else
            {
                root = Delete(root, del);
                printf("%d deleted \n", del);
            }
            break;

        case 6:
            free(root);
            root = NULL;
            exit(0);
        case 7:
            printf("Binary search tree: \n");
            inorder(root);
            printf("\n");
            break;
        default:
            printf("\nWrong option\n");
            break;
        }
    }
}