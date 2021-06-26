#include<stdio.h>


struct address 
        { 
    char name[50];char street[100];char city[50];char state[20];int pin; 
    };
    
struct address rs();

int main()

{   struct address a1;
    a1=rs();
    printf("\n\nreturned address from function to main is : \n\nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",a1.name,a1.street,a1.city,a1.state,a1.pin);
 return 0;
}


struct address rs()
{
    struct address a={"SUBRATA BISWAS","Bahirgachi rural road","Ranaghat","West Bengal",741501};
    printf("\nAdreess inside function : \n\nName: %s\nStreet: %s\nCity: %s\nState: %s\nPin: %d",a.name,a.street,a.city,a.state,a.pin);
    return a;
}