/*Insert a node into a sorted singly linked lists at the correct position*/

#include<stdio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };

struct node* start,*tmp;

void insertsort(int key)
{
    struct node*p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=key;
    if(start==NULL||key<start->data)
    {
        tmp->next=start;
        start=tmp;
    }
    else
    {
        p=start;
        while(p->next!=NULL&&p->next->data<key)
            p=p->next;
        tmp->next=p->next;
        p->next=tmp;
    }
}

void display()
{
    tmp=start;
    while(tmp!=0)
    {
        printf("%d\n",tmp->data);
        tmp=tmp->next;
    }
}

int main()
{
    int t;
    while(t)
    {
        int d;
        printf("\nEnter element to insert in sorted position :");
        scanf("%d",&d);
        insertsort(d);
        printf("do you want to continue(0,1):");
        scanf("%d",&t);
    }
    
    display();
    return 0;
}