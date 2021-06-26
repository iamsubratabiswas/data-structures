#include <stdio.h>  
int getarray(int arr[])  
{  
  int i;
    printf("\nElements of array are : ");  
    for(i=0;i<5;i++)  
    {  
        printf("%d ", arr[i]);  
    }  
    printf("\nenter index whose value to be returned ");
    scanf("%d",&i);
    return (arr[i]);

}  
int main()  
{  int r;
int arr[5]={45,67,34,78,90};
   r=getarray(arr);
   printf("\nreturned value is : %d",r); 

   return 0;  
}  