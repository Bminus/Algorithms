#include<stdio.h>
void merge(int* arr,int first,int middle,int last)
{
	int output[100000];
	int i,j,k;
	k=first;
	j=middle+1;
	for(i=first;i<=middle && j<=last;)
	{
		if(arr[i]<arr[j])
		{
			output[k++]=arr[i];
			i++;
		}
		else
		{
			output[k++]=arr[j];
			j++;
		}
	}
	if(j<=last)
	{
		while(j<=last)
		{
			output[k++]=arr[j];
			j++;
		}
	}
	else if(i<=middle)
	{
		while(i<=middle)
		{
			output[k++]=arr[i];
			i++;
		}
	}
	for(i=first;i<=last;i++)
	{
		arr[i]=output[i];
	}
}

int mergesort(int* arr,int first,int last)
{
		        if(first<last)
		         {
				            int middle=(first+last)/2;
			                    mergesort(arr,first,middle);
			                    mergesort(arr,middle+1,last);
			                    merge(arr,first,middle,last);
		         }
 }
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

