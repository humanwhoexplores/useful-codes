#include<iostream>
#include<cstdio>
#include<cmath>
 using namespace std;
 
int  fac(int);
 
int main()
 
{
    
int num,n,j=1;
int ans;
 
cin>>n;
while(j<=n)
{
cin>>num;
 
ans=fac(num);
 
cout << ans<< endl;
 
j++;
}
 
 
 
}
 
 
 
int fac(int n)
{int e=1;
int count=0;
int i;

while(n>=i)
{
	i=pow(5,e);

count=count+(n/i);

 
 e++;
}
return count;

}  
