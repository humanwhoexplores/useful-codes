
# define gc getchar_unlocked

inline int read ()
{
	char c;
	int n = 0;
 
	while ((c = gc ()) < 48);
	n += (c - '0');
	
	while ((c = gc ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}
