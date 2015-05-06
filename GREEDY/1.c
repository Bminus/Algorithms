//activity selection problem
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int start;
	int finish;
	int flag;
};
int main()
{
	int n;
	printf("Enter the number of activities\n");
	scanf("%d",&n);
	int i;
	struct node array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i].start);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i].finish);
		array[i].flag=0;
	}
	int j;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(array[j].finish>array[j+1].finish)
			{
				int temp=array[j].finish;
				array[j].finish=array[j+1].finish;
				array[j+1].finish=temp;
				temp=array[j].start;
				array[j].start=array[j+1].start;
				array[j+1].start=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d ",array[i].start,array[i].finish);
	}
	printf("\n");
	int count=0;
	for(i=1;i<n;i++)
	{
		if(array[i].start>array[i-1].finish)
		{
			if(array[i-1].flag==0)
				count=count+2;
			else
				count++;
			array[i-1].flag=1;
			array[i].flag=1;
		}

	}
	printf("%d ",count);


	return 0;
}

