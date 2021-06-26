#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[]={1,3,4,5,7,8,9,45,11,65,2,6};
    int num,i,p,c=0;
    int n=sizeof(a)/sizeof(a[0]);
    printf("\n\nsize of array is %u bytes and length is %d",sizeof(a),n);
    printf("\nEnter a value :\n");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {

        if(a[i]==num)
        {
            p=i;
            printf("Element index is %d",p);
            c=1;
            break;
        }
        else
        {
            c=0;
        }

        if(c==0)
        {
           // printf("Number is not in Array: \n");

        }

    }
     printf("\nenter index of array ");
     scanf("%d",&i);
     if(i<n)
     printf("\nvalue of a[%d] ia %d",i,a[i]);
     else
     printf("\nyou put an invalid index");
     

}