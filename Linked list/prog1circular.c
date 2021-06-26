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
    };
    struct node *head,*newnode,*p,*t;
    int l=0;   

 void create()
 {
      int choice;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data element:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=newnode;
            p=head;
        }
        else
        {
            p->next=newnode;
            p=newnode;
        }
        t=p;
        p->next=head;
        printf("do you want to continue(0,1):");
        scanf("%d",&choice);
    }
 }

 void display()
 {
     if(head==0)
     {
         printf("\nthe list is empty\n");
     }
     else
    {

         p=head;
       while(p->next!=head)
     {
        printf("%d\n",p->data);
        p=p->next;
     }
     printf("%d\n",p->data);
    }
 }

void isempty()
 {
     if(head==NULL)
        printf("\n the list is empty");
     else
        printf("\n the list is not empty");
 }

void getlength(){
      l=0;
     p=head;
     do
     {
         l++;
         p=p->next;
     }
     while(p!=head);
     printf("length is =%d",l);
 }

 void insertbeg()
 {
     l++;
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data u want to insert at begining\n");
   scanf("%d",&newnode->data);
   newnode->next=0;
   if(t==0)
   {
       t=newnode;
       t->next=newnode;
   }
   else
   {
       newnode->next=t->next;
       t->next=newnode;
       head=newnode;
   }
   display();
 }

 void insertend()
 {
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("\nenter data u want to insert at end:");
   scanf("%d",&newnode->data);
   newnode->next=0;
   t->next=newnode;
   t=newnode;
   t->next=head;
   display();
 }

 void insert()
 {
   int pos;
   printf("\nenter the position u want to insert:");
   scanf("%d",&pos);
   if(pos==1)
        insertbeg();
   else if(pos<1||pos>l)
            printf("invalid");
   else
   {
       int i=1;
       newnode=(struct node*)malloc(sizeof(struct node));
        l++;
        printf("enter data  ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        p=head;
        while(i<pos-1)
        {
            p=p->next;
            i++;
        }
        newnode->next=p->next;
        p->next=newnode;
        display();
   }

 }

 void delfrombeg()
 {
     p=head;
     if(head==0)
        printf("list is empty\n");
     else if(t==head)
     {
         l--;
         head=0;
         free(p);

     }
     else
     {
         l--;
     printf("\ndeleting from begining\n");
     p=head;
     head=head->next;
     t->next=head;
     free(p);
     display();
     }
 }

void delfromend()
{
    l--;
    printf("deleting from end\n");
  struct node*current,*prev;
  current=head;
  prev=current;
  while(current->next!=t->next)
  {
      prev=current;
      current=current->next;
  }
  prev->next=t->next;
  t=prev;
  free(current);
  display();
}

void delete()
{
    int pos;
    printf("\nenter position u want to delete:");
    scanf("%d",&pos);
    if(pos==1)
        delfrombeg();
    else if(pos==l)
        delfromend();
    else if(pos<1||pos>l)
        printf("invalid");
        else
        {
            struct node*cur=head;
            int i=1;
            while(i<pos-1)
            {
                i++;
                cur=cur->next;
            }
            p=cur->next;
            cur->next=p->next;
            free(p);
            display();
        }
}

void lookup()
{
    int key;
    printf("\n Enter the element to be lookup :");
    scanf("%d",&key);
    p=head;
    do
    {
        if(p->data==key)
        {
           printf("\nElement is found");
           return;
        }
        p=p->next;
    }
     while(p!=head);
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