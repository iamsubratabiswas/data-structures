#include<stdio.h>
 int main()
    {
     /* 2D array declaration*/ 
    int arr[2][7];
     int i,j;
     for(i=0; i<2; i++)
     { for(j=0;j<7;j++)
         {
 printf("Enter value for arr[%d][%d]:", i, j);
        scanf("%d", &arr[i][j]);
             }
         }
     //Displaying array elements 
  printf("Two Dimensional array elements:\n");
     for(i=0; i<2; i++)
     { for(j=0;j<7;j++)
         { printf("%d ", arr[i][j]);
             if(j==7)
                {
                 printf("\n");
                 }
             }
         }
     return 0;
     }