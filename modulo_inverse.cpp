#include <iostream>
#include <vector>
using namespace std;
 
vector<int> 
int inverseArray( long long int n, int m) 
{
    vector<int> 
	modInverse(n + 1, 0);
    modInverse[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        modInverse[i] = (-(m / i) * modInverse[m % i]) % m + m;
    }
    modInverse=modInverse%1000000007;
    
    return modInverse;
}

int main()
{
    
	
	int N,ans,places,size,a,m,multiply; long long int temp,temp2,temp3;
	cin>>N;
	long long int factorial[1000050];
	factorial[0]=1;
	for(int i=1;i<=N+6;i++)
	{
	
	   factorial[i]=factorial[i-1]*i;
	   factorial[i]=factorial[i]%1000000007;
	   
		
	}
	
	
	if(N<13)
	   cout<<"0\n";
	if(N==13 || N==14)
	    cout<<"1\n";
	if(N>14)
	{
		if(N%2==0)
		     places=N-14;
		if(N%2!=0)
		      places=N-13;
			  
			size=places/2;
	
		vector<int>::iterator it;
    
    
    
    for(int i=1;i<=N+6;i++)
	{
	
	   factorial[i]=factorial[i-1]*i;
	   factorial[i]=factorial[i]%1000000007;
	}
	
    int g;
    temp=1;
    for( g=1;g<=places;g++)
      {
      	temp=temp*i;
      	temp=temp%1000000007;
      }
    
     temp2=temp*720;
     temp2=temp2%1000000007;
     
    m=1000000007;
    //a=123;
	//cout<<inverseArray(a, m)[a];
    multiply=inverseArray(temp2,m);
    
    ans=multiply*factorial[N+6];ans=ans%1000000007;
    cout<<ans<<"\n";
    
    }
    
    
    
    return 0;
}
