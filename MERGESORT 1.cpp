#include<iostream>


int mergesort(int[],int[],int[],int,int,int);

int main()
{
	int a1[20],b2[20];
	
	
	int size1,size2,size3;
	
	int i;
	int j1=0;
	
	std::cout<<"\n enter the size of array1 a1  (max 20)";
	std::cin>>size1;
	std::cout<<"\n enter the size of array 2   (max 20)";
	std::cin>>size2;
	
	std::cout<<"\n enter contents of array 1 (a1)";
	for(i=0;i<size1;i++)
	std::cin>>a1[i];
	
	std::cout<<"\n enter contents of array 2 (b2)";
	for(i=0;i<size2;i++)
	std::cin>>b2[i];
	
	size3=size1+size2;
	int c3[size3];
	mergesort(a1,b2,c3,size1,size2,size3);
	
	std::cout<<"\n the sorted array is";
	for(i=0;i<size3;i++)
	std::cout<<c3[size3]<<"\t";
	
	
}

int mergesort(int a1[],int b2[],int c3[],int size1,int size2,int size3)
{
		int l1,l2,l3;
	
            		
 		for(l1=0,l2=0,l3=0;l1<size1,l2<size2,l3<size3;)
		{
			if(a1[l1]<=b2[l2])
			{
				c3[l3]=a1[l1];
			l1+=1;
			}
			else
			{
			c3[l3]=b2[l2];
			l2+=1;
		    }
		    l3+=1;
		}
	
	return c3[size3];
}
