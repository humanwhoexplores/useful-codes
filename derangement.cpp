#include<stdio.h>

long long fact (long long n)
{
	long long temp=1,ans=1;
	while(temp<=n)
	{
		ans=ans*temp;
		
		
		temp++;
		
	}
	
	return  ans;
	
}


int main()
{
	long long t,n,i,up,sum;
	scanf("%lld",&t);
	while(t--)
	{  sum=0;
		scanf("%lld",&n);
		 up=fact(n);
		 sum=sum+up;
		for(i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				sum=sum + (up/fact(i));
			}
			if(i%2!=0)
			 {
			 	sum=sum - (up/fact(i));
			 }
		} 
		
		printf("%lld\n",sum);
		
	}
	
	return 0;
}
