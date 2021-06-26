#include <stdio.h>
int pa1(int);
int pa2(int *);
int main()
{
    int num[]={2,3,5,6,7,9,3,5,7,10};
    int i;
    printf("\narray obtained  by value passing : ");
   for(i=0;i<10;i++)
   pa1(num[i]) ; //value passing 
    printf("\narray obtained  by value passing : ");
     for(i=0;i<10;i++)
     pa2(&num[i]) ; //reference passing 
    return 0;
}
int pa1(int m)
{
    printf("\n%d",m);

}
int pa2(int *n)
{
    printf("\n%d",*n);
}