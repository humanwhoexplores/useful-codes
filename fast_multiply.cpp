#include<stdio.h>




long long multiple(long long a, long long b, long long c) // a * b % c

{

  if (b == 0) {  //Base case a * 0 =0

      return 0;

  }

  long long ret = multiple(a, b >> 1, c) ; //Multiply a by (b>>1).

  ret = (ret + ret) % c;  //we double the value of ret i. 2 * (a * (b>>1)). Take MOD in this step

  if (b & 1) {  //implies b is ODD

      ret = (ret + a) % c;  //if b is odd then we express it as a * b = a+ a * (b>>1). We have computed a*(b>>1) in the previous step by recursion i.e the value ret. We now add the extra a to it.

  }

  return ret;
}



int main()
{    
      unsigned long long a,b,c;
	 a=10000000000; b=100000000000000; c=1234567890;
   
     //a=10; b= 5;
    // c=3;

	printf("%llu\n",multiple(a,b,c));
	
	
}
