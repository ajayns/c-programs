// Function to find 2nd min and max elements of an array

#include <stdio.h>

void maxmin(int array[20], int n)
{
	int i,j,swap,position,max2,min2;

	for(i=0;i<(n-1);i++)
   	{
      position = i; 
      for(j=i+1; j<n ;j++) {
         if(array[position]>array[j])
            position = j;
      }
      if(position!=i)
      {
         swap = array[i];
         array[i] = array[position];
         array[position] = swap;
      }
   	}
 
	printf("The second minimum is=%d\nThe second maximum is=%d\n",array[1],array[n-2]);
}
void main()
{
	int a[20],n,i;	
	printf("Enter size of an array:\n");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	maxmin(a,n);
}


