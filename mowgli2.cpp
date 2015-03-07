#include<iostream>
#include <stdio.h>
#include <string.h>
#include<math.h>
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
 
 
 
void markMultiples(bool arr[], int a, int n)
{        //  copied from geeks for geeks
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
int sieve(int n,int *yoyo)
{    int size=0;
      // copied from geeks for geeks
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                
                yoyo[size]=i+1; size++;   // return the number of elements in yoyo[] which stores all prime factors<=number
				markMultiples(arr, i+1, n);
            }
        }
    }
return size;  
}
 
 
int main()
{
    int N,i,j,z,g,R,great,temp,temp2,flag,size,T,M,Q,yoyo[100001],arr[100000],length,count,ptr;
	 long long up,down,ans,jaat;
    scanf("%d",&T);    //   yoyo stores all primes <=N....  hash1 all primes for numerator hash2 for denominator
    while(T--)
    {
    scanf("%d%d%d",&N,&M,&Q);
    size=sieve(N,yoyo);   //  number of prime numbers <= N;
     
	
	while(Q--)
	{     //  flag =1 if R>=N-R  else flag=2
	     up=1;down=1;ans=1;
   	    
	     
		scanf("%d",&R);
		if(R>=N-R)
		  {
		  	great=R;  // by this i calculate greater (R,N-R) ;; as it is cancelled by numerator
		  	flag=1;  //   i dont calculate this and start numerator operation from great+1 till N
		  }
		if(N-R>R)
		 {
		 	great=N-R;
		 	flag=2;
		 }
	      temp2=great+1;
	      while(temp2<=N)
	     {  length=0;
 	      temp=temp2;   //    by temp2 i iterate from great+1 till N ;;; temp stores current value of temp2
         for(j=0;j<size && yoyo[j]<=temp;)
         { 
         	if(temp%yoyo[j]==0)
         	  {
         	  temp=temp/yoyo[j];        //   operation done on temp;;;   temp bcomes temp/factor
         	  //hash1[yoyo[j]]+=temp2;    //   but temp2 remains constant for one iteration of the loop then temp2++ for next iter
              arr[length]=yoyo[j];
                length++;
			  
			  }
         	if(temp%yoyo[j]!=0)  j++;
         	
         }
         
         arr[length]=-1;
         length++;
         
         
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
		{
		  //cout<<"the frequency of    "<<arr[ptr]<<"======"<<count<<"\n";  	
		  up=up*modular_pow(arr[ptr],count*temp2,M);
		  if(up>=M)
		    up>=M;
				
			count=1;
			ptr++;
		}
		
	   
	}
	
         
         
         
         
         
         
         
         
		  temp2++;
	    }
		 	
	    if (flag==2 && R>=2)   //  means  N-R>R ;;;  find powers for R;
	    {  temp2=2;  
		   while(temp2<=R)
		   {   length=0;
		      temp=temp2;
	    	for(j=0;j<size && yoyo[j]<=temp;)
	    	{
	    		if(temp%yoyo[j]==0)
	    		  { 
				  temp=temp/yoyo[j]; // hash2[yoyo[j]]+=temp2;
	    	      arr[length]=yoyo[j];
	    	      length++;
				  }
	    		if(temp%yoyo[j]!=0) j++;  
	    	}
	    	
	    	arr[length]=-1;
	    	length++;
	    	
	    	
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
		{
		  //cout<<"the frequency of    "<<arr[ptr]<<"======"<<count<<"\n";  	
		  down=down*modular_pow(arr[ptr],count*temp2,M);
		  if(down>=M)
		    down>=M;
				
			count=1;
			ptr++;
		}
		
	   
	}
	
	    	
	    	
	    	
	    	
	    	
	    	
	         temp2++;
	       }
		}
        
		
	    if (flag==1 && N-R>=2)   //  means  R>=N-R ;;;  find powers for R;
	    {  temp2=2;  
		   while(temp2<=N-R)
		   {  length=0;
		     temp=temp2;
	    	for(j=0;j<size && yoyo[j]<=temp;)
	    	{
	    		if(temp%yoyo[j]==0)
	    		  { 
				  temp=temp/yoyo[j];  //hash2[yoyo[j]]+=temp2;
	    	      arr[length]=yoyo[j];
	    	      length++;
				  
				  }
	    		if(temp%yoyo[j]!=0) j++;  
	    	}
	    	arr[length]=-1;
	    	length++;
	    	
	    	
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
		{
		  //cout<<"the frequency of    "<<arr[ptr]<<"======"<<count<<"\n";  	
		  down=down*modular_pow(arr[ptr],count*temp2,M);
		  if(down>=M)
		    down>=M;
				
			count=1;
			ptr++;
		}
		
	   
	}
	
	    	
	    	
	    	
	         temp2++;
	       }
		}
       
     
 
       
       ans=up/down;
       if(ans>=M)
        ans=ans%M;
        
        printf("%lld\n",ans);
       
       
       
 
     }
    
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
    
	return 0;
} 
