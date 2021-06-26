/*Write a C program to implement a stack using array*/

#include<stdio.h>
int stack[5];
int top=-1;
void push()
{
    int x;
    printf("enter data\n");
    scanf("%d",&x);
    if(top==4)
        printf("overflow");
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int x;
    if(top==-1)
        printf("underflow");
    else
    {
        x=stack[top];
        top--;
        printf("pop item is %d",x);
    }
}
void peek()
{
    if(top==-1)
        printf("underflow");
        else
        {
            printf("top item is %d",stack[top]);
        }
}
void display()
{
    if(top==-1)
        printf("stack is empty");
        else
        {
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
        }
}
int main()
{
    int t;
    do{
    printf("Enter choice: 1 push: 2 pop: 3 peek: 4 display: 0 exit");
    scanf("%d",&t);

    switch(t)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    default:
        printf("invalid choice");
    }
    }while(t!=0);
    return 0;
}

