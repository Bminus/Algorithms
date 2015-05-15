//binary search
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int ans;
void binary_search(int* arr,int search,int first,int last)
    {
    if(first<=last)
        {
        int middle=(first+last)/2;
        if(arr[middle]==search)
            {
            ans=middle;
        }
        else if(arr[middle]>search)
            {
            binary_search(arr,search,first,middle-1);
        }
        else
            {
            binary_search(arr,search,middle+1,last);
        }
        }
    }

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int v,n;
    int arr[1000000];
    int i;
    scanf("%d %d",&v,&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&arr[i]);
    }
    binary_search(arr,v,0,n-1);
    printf("%d\n",ans);
    return 0;
}
