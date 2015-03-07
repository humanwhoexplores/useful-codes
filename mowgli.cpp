#include<iostream>
using namespace std;

#define ll long long
 
ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
 




int main()
{   int length,count,ptr; long long up,M=24;
	int arr[12]={2,2,2,3,3,5,5,7,11,17,17,-1};
	length=12;
      count=1,ptr;
	ptr=0;
	while(ptr<length)
	{   count=1;
        if(ptr==length-1)
           break;
		
		
		
				
		while(arr[ptr]==arr[ptr+1])
		{
			count++;
			ptr++;
			
		}
		
		if(arr[ptr]!=arr[ptr+1]  )
		{  up=1;
		  cout<<"the frequency of    "<<arr[ptr]<<"======"<<count<<"\t";  	
		  up=up*modular_pow(arr[ptr],count,M);
		  if(up>M)
		    up>M;
		  cout<<up<<"\n";	
			count=1;
			ptr++;
			
		}
		
	   
	}
	
	
	
	
	
}
