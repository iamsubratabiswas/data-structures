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
  struct node *head, *newnode, *p;
  int count;
void create()
 {
    int choice;
    head=0;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
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
        printf("do you want to continue (0,1)");
        scanf("%d",&choice);
    }
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
        printf("linked list is empty");
     else
        printf("linked list is not empty");
 }
 void getlength()
 {
      count=0;
     p=head;
     while(p!=NULL)
     {
      count++;
         p=p->next;
     }
     printf("length is = %d\n",count);
 }
void insert()
 {
     int i=1,position;
  printf("\n next to the position u want to insert ");
  scanf("%d",&position);
  if(position>count)
  {
      printf("invalid position");
  }
  else
  {
      while(i<position)
      {
          p=p->next;
          i++;
      }
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nenter data to insert ");
  scanf("%d",&newnode->data);
  newnode->next=p->next;
  p->next=newnode;
  }
 }

void delete()
 {
     p=head;
   struct node *nextnode,*a;
   a=head->next;
   int position,i=1;
   printf("\nenter the position u want to delete ");
   scanf("%d",&position);
   while(i<position-1)
   {
       p=p->next;
       i++;
   }
   nextnode=p->next;
   p->next=nextnode->next;
   free(nextnode);
   }

void lookup()
{
    int key;
    printf("\nEnter element to lookup ");
    scanf("%d",&key);
    p=head;
    while(p!=NULL)
    {
        if(p->data==key)
        {
           printf("\nElement found");
           return;
        }
        p=p->next;
    }
    printf("\nElement not found");
}


int main()
{
    create();
    isempty();
    getlength();
    insert();
    delete();
    lookup();
    return 0;
}