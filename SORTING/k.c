#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
    {
    return *(int *)a-*(int *)b;
}
int main() {
    int test;
    scanf("%d",&test);
    while(test--)
        {
    int n;
    scanf("%d",&n);
    int i;
    int arr[n];
    for(i=0;i<n;i++)
        {
        scanf("%d",&arr[i]);
    }
    long long int count=0;
    int c[1000001]={0};
    for(i=0;i<n;i++)
        {
        c[arr[i]]++;
    }
    for(i=0;i<=1000000;i++)
        {
        if(c[i]>1)
            {
            count+=(c[i]*(c[i]-1));
        }
    }
    printf("%lld\n",count);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}