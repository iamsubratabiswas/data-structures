/*Write a C program to implement a queue and a circular queue using array.*/

#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front=-1,rear=-1;
void enqueue(int x)
{
    if(rear==4)
    {
        printf("over flow\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
        printf("under flow\n");
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        printf("deleted element is %d\n",queue[front]);
        front++;
    }
}
void display()
{
    int i;
     if(front==-1&&rear==-1)
        printf("under flow\n");
        else
        {
            for(i=front;i<rear+1;i++)
                printf("%d\n",queue[i]);
        }
}
void peek()
{
     if(front==-1&&rear==-1)
        printf("under flow\n");
        else
            printf("%d\n",queue[front]);
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}

