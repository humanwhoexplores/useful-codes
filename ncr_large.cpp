2.Using Recurrence Relation for nCr
The recurrence relation for nCr is C(i,k) = C(i-1,k-1) + C(i-1,k). Thus we can calculate nCr in time complexity O(n*r) and space complexity O(n*r).
 
#include<iostream>
using namespace std;
#include<vector>

/*
	C(n,r) mod m
	Using recurrence:
	C(i,k) = C(i-1,k-1) + C(i-1,k)
	Time Complexity: O(n*r)
	Space Complexity: O(n*r)
*/
long long C(int n, int r, int MOD)
{
	vector< vector<long long> > C(n+1,vector<long long> (r+1,0));

	for (int i=0; i<=n; i++)
	{
		for (int k=0; k<=r && k<=i; k++)
			if (k==0 || k==i)
				C[i][k] = 1;
			else
				C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
	}
	return C[n][r];
}
int main()
{
	int n,r,m;
	while (~scanf("%d%d%d",&n,&r,&m))
	{
		printf("%lld\n",C(n, r, m));
	}
}


We can easily reduce the space complexity of the above solution by just keeping track of the previous row as we don’t need the rest rows.

3. Using expansion of nCr
Since
C(n,k) = n!/((n-k)!k!) 
                [n(n-1)...(n-k+1)][(n-k)...(1)]  
           =   -----------------------------------------
                 [(n-k)...(1)][k(k-1)...(1)]

We can cancel the terms: [(n-k)...(1)] as they appear both on top and bottom, leaving:
    n  (n-1)        (n-k+1) 
    -   -----   .....  --------- 
    k  (k-1)           (1)
which we might write as:
C(n,k) = 1,                 if k = 0 
          = (n/k)*C(n-1, k-1), otherwise

4. Using the power of prime p in n factorial
The power of prime p in n factorial is given by
ep = ?n/p? + ?n/p^2? + ?n/p^3?…
If we call the power of p in n factorial, the power of p in nCr is given by
e = countFact(n,i) – countFact(r,i) – countFact(n-r,i)
To get the result we multiply p^e for all p less than n.
 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
#include<iostream>
using namespace std;
#include<vector>

/* This function calculates power of p in n! */
int countFact(int n, int p)
{
	int k=0;
	while (n>0)
	{
		k+=n/p;
		n/=p;
	}
	return k;
}

/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
	long long x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}

long long C(int n, int r, int MOD)
{
	long long res = 1;
	vector<bool> isPrime(n,1);
	for (int i=2; i<=n; i++)
		if (isPrime[i])
		{
			for (int j=2*i; j<=n; j+=i)
				isPrime[j]=0;
			int k = countFact(n,i) - countFact(r,i) - countFact(n-r,i);  
			res = (res * pow(i, k, MOD)) % MOD;
		}
	return res;
}

int main()
{
	int n,r,m;
	while (scanf("%d%d%d",&n,&r,&m))
	{
		printf("%lld\n",C(n,r,m));
	}
}
