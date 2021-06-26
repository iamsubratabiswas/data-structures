#include <stdio.h>  
int getarray()  
{ int a[]={1,3,4,5,7,8,9,45,11,65,2,6};
    int n=sizeof(a)/sizeof(a[0]);
    return(n);
}  
int main()
{   int r;
   r=getarray(); 
    printf(" returned array length : %d",r);
   return 0;  
}  