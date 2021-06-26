/* Write a C program to implement a stack using linked list.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=0;
void push(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void display()
{
    struct node *temp=top;
    if(top==0)
        printf("underflow");
    else
    {
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    }
}
void peek()
{
    if(top==0)
        printf("underflow");
    else
    {
        printf("%d\n",top->data);
    }
}
void pop()
{
    if(top==0)
        printf("underflow");
        else
        {
            struct node *temp=top;
            printf("top element is %d\n",top->data);
            top=top->next;
            free(temp);
        }
}
int main()
{
    push(2);
    push(3);
    push(10);
    display();
    peek();
    pop();
    peek();
    display();
    return 0;
}

