#include <stdio.h>
#include <string.h>

int primes[1000000];

 
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
int SieveOfEratosthenes(int n)
{    int p=0;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                
                primes[p]=i+1;   p++;  //  this array stores all prime numbers 
                 markMultiples(arr, i+1, n);
            }
        }
        return p;
    }
}
 
// Driver Program to test above function
int main()
{
    int n = 30,size;
    printf("Following are the prime numbers below %d\n", n);
    size=SieveOfEratosthenes(n);
    printf("\n\n");
    for(int i=0;i<size;i++)
        printf("%d ",primes[i]);
    return 0;
}
