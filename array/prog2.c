#include <stdio.h>
int createarray();
int returnvalue(int,int,int);
int returnsize();
int arraypoint();
int main()

{ 
int r;
r=int createarray();
printf("length of array returned : %d",r);
}

int createarray()
{
   int arr[10][10];
   int size1,size2,i,j,length;
   printf("\nenter row and column number");
   scanf("\n%d\n%d",size1,size2);
   for(i=0;i<size1;i++)
   {
     for(j=0;j<size2;j++)
     scanf("%d ",arr[i][j]);

   }
printf("\ncreated array is :\n");
    for(i=0;i<size1;i++)
   {
     for(j=0;j<size2;j++)
     printf("%d ",arr[i][j]);
     printf("\n");
     
   }
   length=size1*size2;
   int rv=returnvalue();
   return length;
}
int returnvalue()
{int k;
printf("\nenter index whose vale to be returned");
scanf("%d",k);
return k;
}