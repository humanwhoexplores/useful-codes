long long int MOD = 1000000007;
inline long long int mod(long long int x)
{   if(x<0)
     x=x+MOD;      
	if(x<MOD)
		return x;
	
	else
		return x%MOD;
}

