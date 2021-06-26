#include <stdio.h>
int main()
{
    int num[]={2,3,5};
    int i;
    printf("Elements of array are : ");
    for(i=0;i<3;i++)
     printf("\n%d",*(num+i));
}