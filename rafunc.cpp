#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int hello(int array[],int N)
{
	int i=0,j=0,temp;
	while(i<N)
	{
	srand(time(NULL));
	temp=rand()%N;
	
	for(j=0;j<i;j++)
	{
		if(temp ==array[i])
		{
			break;
		}
	}
	 if(j==i)
	   {
	   	array[i]=temp;
	   	i++;
	   }
	
    }
	
	
	
}



int main()
{
	int array[200],N,i;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		printf("%d  ",array[i]);
	}
	
	
	return 0;
	
}
