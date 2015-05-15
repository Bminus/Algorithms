#include<stdio.h>
int binary_search(int* arr,int first,int last,int search)
{
	if(first<last)
	{
		int mid=(first+last)/2;
		if(arr[mid]==search)
			return mid+1;
		if(arr[mid]<search)
			return binary_search(arr,mid+1,last,search);
		if(arr[mid]>search)
			return binary_search(arr,first,mid-1,search);
	}
	else
	{
		if(search<arr[first])
			return first;
		else
			return first+1;

	}
}
		

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int j;
	for(j=1;j<n;j++)
	{
		int item=arr[j];
		int loc=binary_search(arr,0,j-1,arr[j]);
		for(i=j-1;i>=loc;i--)
		{
			arr[i+1]=arr[i];
		}
		arr[loc]=item;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
