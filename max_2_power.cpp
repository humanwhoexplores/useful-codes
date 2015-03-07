#include<iostream>

long long hob (long long  num)
{    /* this returns largest number which is power of 2 <=num*/
    if (!num)
    	return 0;
 
    int ret = 1;
 
    while (num >>= 1)
    	ret <<= 1;
 
    return ret;
 
}



