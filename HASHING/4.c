//deleting in hashing by linear probing
#include<stdio.h>
int main()
{
	int tablesize;
	scanf("%d",&tablesize);
	int n;
	scanf("%d",&n);
	int arr[tablesize];
	int i=0;
	int j;
	for(j=0;j<tablesize;j++)
		arr[j]=-1;
	int pos;
	for(j=0;j<n;j++)
	{
		int a;
		scanf("%d",&a);
		i=0;
		while(1)
		{
			pos=(a+i)%tablesize;
			if(arr[pos]==-1)
			{
				arr[pos]=a;
				break;
			}
			else
				i++;
		}
	}
	for(j=0;j<tablesize;j++)
		printf("%d ",arr[j]);
	int search;
	scanf("%d",&search);
	int l=0;
	int posi;
	int flag=0;
	while(l<=n)
	{
		posi=(search+l)%tablesize;
		if(arr[posi]==search)
		{
			printf("Found\n");
			flag=1;
			for(j=posi+1;j<tablesize;j++)
			{
				if(arr[j]%tablesize<=posi)
				{
					arr[posi]=arr[j];
					arr[j]=-1;
					posi=j;
					flag=2;
				}
			}
			if(flag==1)
				arr[posi]=-1;
			break;
		}
		
		else
			l++;
	}
	if(flag!=1)
		printf("Not Found");
	return 0;
}

