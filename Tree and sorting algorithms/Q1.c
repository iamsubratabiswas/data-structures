/*
Write a menu driven program to do the following 
a. Create a binaary tree of your own choice.
b. Perform in-order traversal.
c. Perform pre-order traversal.
d. Perform post-order traversal.
*/



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
	struct node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=create();
 
	printf("Enter right child of %d:\n",x);
	p->right=create();
	
	return p;
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

void preorder(struct node *Node)
{
    if (Node != NULL)
    {
        printf("%d ", Node->data);
        preorder(Node->left);
        preorder(Node->right);
    }
}

void postorder(struct node *Node)
{
    if (Node != NULL)
    {
        postorder(Node->left);
        postorder(Node->right);
        printf("%d ", Node->data);
    }
}

int main()
{ 
    int ch = 0;
    struct node* root = NULL;
   while (1)
    {
        printf("\n1.create binary tree\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create();
        case 2:
            printf("\nInorder Traversal: \n");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal: \n");
            preorder(root);
            break;
        case 4:
            printf("\nPostorder Traversal: \n");
            postorder(root);
            break;
        case 5:
            free(root);
            root = NULL;
            exit(0);
        default:
            printf("\nWrong option");
            break;
        }
    }
}