#include<stdio.h>
int main()
{
struct address 
{ 
char name[50];char street[100];char city[50];char state[20];int pin; 
};
    
struct address a1={"SUBRATA BISWAS","Bahirgachi rural road","Ranaghat","West Bengal",741501};
    struct address *a2;
    a2=&a1;
  
    printf("\nAdreess is: \nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",a2->name,a2->street,a2->city,a2->state,a2->pin);
}