#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
    {
    int data;
    char string[10];
};
int main() {
    int n;
    scanf("%d",&n);
    int i;
    struct node *arr=(struct node*)malloc(sizeof(struct node)*n);
    struct node *output=(struct node*)malloc(sizeof(struct node)*n);
    int c[101]={0};
    for(i=0;i<n;i++)
        {
        scanf("%d",&arr[i].data);
        getchar();
        scanf("%s",arr[i].string);
        //printf("%s",arr[0].string);
    }
    for(i=0;i<n;i++)
        {
        c[arr[i].data]++;
    }
    for(i=1;i<=100;i++)
        {
        c[i]+=c[i-1];
    }
    for(i=n-1;i>=n/2;i--)
        {
        output[c[arr[i].data]].data=arr[i].data;
         strcpy(output[c[arr[i].data]].string,arr[i].string);
        c[arr[i].data]--;
    }
    
    for(i=n/2-1;i>=0;i--)
        {
           //output[c[arr[i].data]].data=arr[i].data;
         strcpy(output[c[arr[i].data]].string,"-");
        c[arr[i].data]--;
    }
    for(i=1;i<=n;i++)
        {
        printf("%s ",output[i].string);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
