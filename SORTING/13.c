//radix sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int max(int *arr,int n)
{
	int max=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
void countsort(int *arr,int exp,int n)
{
	int temp[10]={0};
	int *output=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		temp[(arr[i]/exp)%10]++;
	for(i=1;i<10;i++)
		temp[i]=temp[i]+temp[i-1];
	for(i=n-1;i>=0;i--)
	{
		output[temp[(arr[i]/exp)%10]]=arr[i];
		temp[(arr[i]/exp)%10]--;
	}
	for(i=1;i<=n;i++)
		arr[i-1]=output[i];
}
void radixsort(int *arr,int n)
{
	int m=max(arr,n);
        int exp;
	for(exp=1;m/exp>0;exp=exp*10)
		countsort(arr,exp,n);
}
int main()
{
	int n;
        time_t t;
	scanf("%d",&n);
	srand((unsigned)time(&t));
        int i;
	int *arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		arr[i]=rand()%50;
	radixsort(arr,n);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}