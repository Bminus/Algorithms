#include<stdio.h>
#include<math.h>
int numTrees(int n) {
    //(2*n)!/n!*(n+1)!
    //catalan number
    int k=n;
    int i;
    double prod=1;
    for(i=2*n;i>=n+1;i--)
    {
        prod*=(double)i/k;
	printf("%lf\n",prod);
        k--;
     }
     k=n+1;
     for(i=n;i>=1;i--)
     {
         prod*=(double)i/k;
	 printf("%lf\n",prod);
         k--;
     }
     int b;
     b=(int)ceil(prod);
     return b;
     
}
int main()
{
    printf("%d",numTrees(11));
}
