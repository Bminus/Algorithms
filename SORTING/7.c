#include<stdio.h>
#include<limits.h>
int cmp(const void* a,const void* b)
{
	return *(int *)a-*(int*) b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int arr1[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		arr1[i]=arr[i];
	}
	int count=0;
	int flag=1;
	int min,max;
	min=INT_MAX;
	max=INT_MIN;
	int flag1=1;
	for(i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			flag1=0;
			break;
		}
	}
	if(flag1==1)
		printf("yes\n");
	else
	{
		qsort(arr,n,sizeof(int),cmp);
		int x=-1;
		int y=-1;
		for(i=0;i<n;i++)
		{
			if(arr[i]!=arr1[i])
			{
				//x=2 y=4
				if(arr[i]!=y &&  arr1[i]!=x)
				x=arr[i];
				y=arr1[i];
			}
		}
		
	/*for(i=2;i<=n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			if(i-1<min)
				min=i-1;
			if(i>max)
				max=i;
			count++;
			flag=2;
		}
		else if(flag==2 && arr[i]>arr[i-1])
		{
			break;
		}
	}
	int j;
	for(j=i+1;j<=n;j++)
	{
		if(arr[j]<arr[j-1])
		{
			flag=-1;
			break;
			
		}
	}
	if(flag==2)
	{
		printf("yes\n");
		printf("reverse %d %d",min,max);
	}*/
	}
	return 0;
}




