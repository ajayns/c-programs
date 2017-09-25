// Function to find the max and min number in an array

#include<stdio.h>

void maxmin(int a[20], int n)
{
	int max=a[0],i;
	for(i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
	int min=a[0];
	for(i=1;i<n;i++)
		if(a[i]<min)
			min=a[i];
	printf("The minimum number is= %d\nThe maximum number is= %d\n",min,max);
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


