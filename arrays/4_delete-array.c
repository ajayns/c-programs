// Delete an element in an array

#include <stdio.h>

void del(int a[20], int n, int p) {
	int i;
	if(p<0 || p>n)
	{
		printf("Error!");
		return;	
	}
	for(i=p-1;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
}

void main()
{
	int i,a[20],n,p,t;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter position: ");
	scanf("%d",&p);
	
	del(a,n,p);

	printf("Modified array:\n");
	for(i=0;i<n-1;i++)
		printf("%d",a[i]);
}
		

	
