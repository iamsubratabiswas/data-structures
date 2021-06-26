/*Write a C program to implement a queue and a circular queue using linked list.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0&&rear==0)
    {
        front=newnode;
        rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void display()
{
    struct node *temp;
    if(front==0&&rear==0)
        printf("queue is empty\n");
    else
    {
        temp=front;
        while(temp->next!=front)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void dequeue()
{
    struct node *temp=front;
    if(front==0&&rear==0)
        printf("under flow\n");
        else if(front==rear)
        {
            front=0;
            rear=0;
            free(temp);
        }
        else
        {
            printf("deleted element is %d\n",front->data);
            front=front->next;
            rear->next=front;
            free(temp);
        }
}
void peek()
{
    if(front==0&&rear==0)
        printf("queue is empty\n");
        else
        {
            printf("%d\n",front->data);
        }
}
int main()
{
    enqueue(5);
    enqueue(0);
    enqueue(6);
    display();
    dequeue();
    peek();
    display();
    return 0;
}


