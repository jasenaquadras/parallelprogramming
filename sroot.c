#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void seive(int *a,long n)
{
	int sqroot=(int)sqrt(100000000);
	#pragma omp parallel for schedule(dynamic,1)
	for(int i=2;i<=sqroot;i++)
	{
		if(a[i])
		{
		
			
			for(int j=i*i;j<=n;j+=i)
			{
			
				a[j]=0;
			
			}
		}
	}
	
}
int main()
{
	
	long n=100000000;
	int *a=(int *)malloc(sizeof(int)*(n+1));
	for(int i=2;i<=n;i++)
		a[i]=i;
	seive(a,n);
	return 0;
}
