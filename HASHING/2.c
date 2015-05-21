//inserting in hashing by linear probing
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
	return 0;
}

