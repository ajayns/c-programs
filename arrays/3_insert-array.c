// Insert an element in an array

#include <stdio.h>

void insert(int a[20], int n, int p, int x) {
	int i;
	if(p<0 || p==n || p>20)
	{
		printf("Error!");
		return;
	}
	for(i=n-1;i>=p-1;i--)
	{
		a[i+1]=a[i];
	}
	a[p-1]=x;
}

void main()
{
	int i,a[20],n,x,p,t;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
           
	}
	printf("Enter position and element: ");
	scanf("%d%d",&p,&x);

	insert(a,n,p,x);
	
	printf("Modified array:\n");
	for(i=0;i<n+1;i++)
		printf("%d\n",a[i]);
}
		

	
