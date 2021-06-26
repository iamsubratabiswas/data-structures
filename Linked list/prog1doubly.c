/*Implement the following functions for singly,doubly and circular lined list
-isEmpty
-getLength
-insert
-delete
-Lookup

*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*newnode,*p,*t;
int count,l=0;

void create()
{
    int choice;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter data element\n");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=newnode;
            t=newnode;
        }
        else
        {
            t->next=newnode;
            newnode->prev=t;
            t=newnode;
        }
        printf("do u want to enter more (0,1):");
        scanf("%d",&choice);
    }
}

void display()
{
    p=head;
    while(p!=0)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void isempty()
 {
     if(head==NULL)
        printf("/nlist is empty ");
     else
        printf("/nlist is not empty");
 }

void getlength()
 {
      l=0;
     p=head;
     while(p!=NULL)
     {
         l++;
         p=p->next;
     }
     printf("\nlength is = %d",l);
 }

 void insertbeg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\ninsert at begining:");
    l++;
    scanf("%d",&newnode->data);
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    display();
}

void insertend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    l++;
    printf("\ninsert at end:");
    scanf("%d",&newnode->data);
    t->next=newnode;
    newnode->prev=t;
    newnode->next=0;
    t=newnode;
    display();
}

void insert()
{
    int pos,i=1;
    printf("\nenter the position u want to insert:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insertbeg();
    }
    else if(pos<1||pos>l)
    {
        printf("\ninvalid\n");
    }
    else
    {

        p=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        l++;
        printf("\nenter data:");
        scanf("%d",&newnode->data);
        while(i<pos-1)
        {
            p=p->next;
            i++;
        }
        newnode->prev=p;
        newnode->next=p->next;
        p->next=newnode;
        newnode->next->prev=newnode;
        display();
    }
}

void delfrombeg()
{
    if(head==0)
    {
        printf("list is empty\n");
    }
    else
    {
        l--;
        printf("delete from begining\n\n");
        p=head;
        head=head->next;
        head->prev=0;
        free(p);
        display();
    }
}

void delfromend()
{
    if(t==0)
    {
        printf("list is empty\n");
    }
    else
   {
       l--;
       printf("delete from end\n");
       p=t;
       t=t->prev;
       t->next=0;
       free(p);
       display();
   }
}

void delete()
{
    int i=1,pos;
    printf("enter the position u want to delete\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        delfrombeg();
    }
    else if(pos==l)
    {
        delfromend();
    }
    else if(pos<1||pos>l)
    {
        printf("invalid position\n");
    }
    else
    {
        p=head;
        while(i<pos)
        {
            p=p->next;
            i++;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        printf("\n");
        display();
    }
}

void lookup()
{
    int key;
    printf("Enter the element to be lookup:");
    scanf("%d",&key);
    p=head;
    while(p!=NULL)
    {
        if(p->data==key)
        {
           printf("\nElement is found");
           return;
        }
        p=p->next;
    }
    printf("\nElement is not found");
}

int main()
{
    create();
    display();
    isempty();
    getlength();
    insert();
    delete();
    lookup();
    return 0;
}