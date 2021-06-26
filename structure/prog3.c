#include<stdio.h>
struct address 
    { 
    char name[50];char street[100];char city[50];char state[20];int pin; 
    };

void ps1(struct address);
void ps2(struct address *);

int main()

{
    
struct address a1={"SUBRATA BISWAS","Bahirgachi rural road","Ranaghat","West Bengal",741501};

    ps1(a1); //pass by value
    ps2(&a1); //pass by reference
  return 0;
}


void ps1(struct address a)
{
   printf("\nAdreess obtained pass by avalue is: \n\nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",a.name,a.street,a.city,a.state,a.pin);
}


void ps2(struct address *pa)
{
    printf("\n\nAdreess obtained pass by reference is: \n\nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",pa->name,pa->street,pa->city,pa->state,pa->pin);
}