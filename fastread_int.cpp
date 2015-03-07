	//fast function to scan various integer data types
template <typename T>
inline T input() {
	T n = 0;
	int s = 1;
	char p = get();
 
	while((p < '0' || p > '9') && p != EOF && p != '-')
		p = get();
 
	if(p == '-'){ s = -1, p = get(); }
 
	while(p >= '0' && p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = get();
	}
	return n*s;
}
 



#define gc getchar_unlocked

inline void fastint(int &x) {
    register int c = gc();
    x = 0;
    int neg = 0;
 
    for(; ((c<48 || c>57) && c != '-'); c = gc());
 
    if(c=='-') {
    	neg = 1;
    	c = gc();
    }
 
    for(; c>47 && c<58 ; c = gc()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
 
    if(neg)
    	x = -x;
}



#define gc getchar_unlocked
inline int scan()
{
	register int n=0,c = gc();
	while(c<48 || c>57)c=gc();
	while(c>47 && c<58)n=(n<<1)+(n<<3)+c-48,c=gc();
	return n;
}

