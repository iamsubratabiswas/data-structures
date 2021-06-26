/* Implement a queue using stack using C Program.*/

#include<stdio.h>
#include<stdlib.h>
int s1[5],s2[5];
int top1=-1,top2=-1,count=0;
void push1(int x)
{
    if(top1==4)
        printf("over flow\n");
    else
    {
        top1++;
        s1[top1]=x;
    }

}
void push2(int x)
{
    if(top2==4)
        printf("over flow\n");
    else
        s2[++top2]=x;
}
void enqueue(int x)
{
    push1(x);
    count++;
}
int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void dequeue()
{
    int i,a,b;
    if(top1==-1&&top2==-1)
        printf("under flow\n");
        else
            for(i=0;i<count;i++)
        {
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("deleted element is %d\n",b);
        count--;
        for(i=0;i<count;i++)
        {
            a=pop2();
            push1(a);
        }
}
void display()
{
    int i;
    for(i=0;i<=top1;i++)
        printf("%d\n",s1[i]);
}
int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    display();
    dequeue();
    enqueue(7);
    display();
    return 0;
}

