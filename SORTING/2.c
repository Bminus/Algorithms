#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*1 4 3 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 2 3 4 5 6*/
void insertionSort(int ar_size, int *  ar) {
int i,j;
    for(i=1;i<ar_size;i++)
        {
        int elem=ar[i];
        for(j=i-1;j>=0;j--)
            {
            if(elem<ar[j])
                {
                ar[j+1]=ar[j];
            }
            else
                {
                break;
            }
        }
            ar[j+1]=elem;
            for(j=0;j<ar_size;j++)
                {
                printf("%d ",ar[j]);
            }
        printf("\n");
            
        }
    }

int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

insertionSort(_ar_size, _ar);
   
   return 0;
}