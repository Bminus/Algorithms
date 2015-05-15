//quicksort
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int ans=-1;
int partition( int *  ar,int first,int last) {

    int pivot=ar[first];
    int i;
    int index=first+1;
    for(i=first+1;i<=last;i++)
        {
        if(ar[i]<pivot)
            {
            int temp=ar[i];
            ar[i]=ar[index];
            ar[index]=temp;
            index++;
        }
    }
    int temp=ar[first];
    ar[first]=ar[index-1];
    ar[index-1]=temp;
    return index-1;

}
void quicksort(int ar_size, int *ar,int first,int last,int k) {
	if(first<=last)
	{
    int p=partition(ar,first,last);
    if(p==k-1)
	    ans=ar[p];
    if(p>k-1)
    quicksort(ar_size,ar,first,p-1,k);
    else
    quicksort(ar_size,ar,p+1,last,k);
	}
   // Complete this function
}
int main(void) {
   int ar_size;
   int k;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) { 
      scanf("%d", &ar[i]); 
   }
   scanf("%d",&k);

   quicksort(ar_size, ar,0,ar_size-1,k);
//    for(i = 0; i < ar_size; i++) { 
  //    printf("%d", ar[i]); 
   // }
      printf("%d ",ans);
  
   
   return 0;
}
