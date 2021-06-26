/*Write a C program to implement a queue and a circular queue using array.*/

#include<stdio.h>
#include<stdlib.h>
int queue[5];
int front=-1,rear=-1;
void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%5==front)
        printf("over flow\n");
    else
    {
        rear=(rear+1)%5;
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
        front=(front+1)%5;
    }
}
void display()
{
    int i=front;
     if(front==-1&&rear==-1)
        printf("under flow\n");
        else
        {
            while(i!=rear)
            {
                printf("%d\n",queue[i]);
                i=(i+1)%5;
            }
            printf("%d\n",queue[rear]);
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
    enqueue(4);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    enqueue(9);
    enqueue(8);
    enqueue(11);
    peek();
    display();
    return 0;
}


