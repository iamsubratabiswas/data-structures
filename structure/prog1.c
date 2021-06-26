#include<stdio.h>
int main()
{
struct address 
{ 
char name[50];char street[100];char city[50];char state[20];int pin; 
};
    
struct address a1={"SUBRATA BISWAS","Bahirgachi rural road","Ranaghat","West Bengal",741501};
  
    printf("\nAdreess is: \nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",a1.name,a1.street,a1.city,a1.state,a1.pin);
}