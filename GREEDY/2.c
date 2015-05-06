//job sequencing problem
#include<stdio.h>
struct node
{
	int deadline;
	int profit;
	char id;
};
int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int i;
	struct node array[n];
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c",&array[i].id);
		scanf("%d",&array[i].deadline);
		scanf("%d",&array[i].profit);
	}
	int j;
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(array[j].profit<array[j+1].profit)
			{
				int temp;
				int temp1;
				char temp2;
				temp2=array[j].id;
				temp=array[j].profit;
				temp1=array[j].deadline;
				array[j].profit=array[j+1].profit;
				array[j].deadline=array[j+1].deadline;
				array[j+1].profit=temp;
				array[j+1].deadline=temp1;
				array[j].id=array[j+1].id;
				array[j+1].id=temp2;
			}
		}
	}
/*	for(i=0;i<n;i++)
	{
		printf("%c %d %d ",array[i].id,array[i].deadline,array[i].profit);
	}*/
		printf("%c ",array[0].id);
		int count=1;
		for(i=1;i<n;i++)
		{
			count+=1;
//			printf("%d %d ",array[i].deadline,count);
			if(array[i].deadline>=count)
			{
				printf("%c ",array[i].id);
			}
			else
				count-=1;
		}
		return 0;
	}



			


