#include<stdio.h>
int cmp(const void* a,const void* b)
{
	return *(int *)a-*(int *)b;
}
int binary_search(int* arr,int first,int last)
{
	int mid=-1;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(arr[mid]==0)
		{
			first=mid+1;
		}
		else if(arr[mid]==1)
		{
			if((mid!=0 && arr[mid-1]==0) || mid==0)
			{
				return mid;
			}
			else
			{
				last=mid-1;
			}
		}
	}
	return -1;
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
	qsort(arr,n,sizeof(int),cmp);
	int l=binary_search(arr,0,n-1);
	if(l==-1)
		printf("0");
	else
		printf("%d",n-l);
	return 0;
}
