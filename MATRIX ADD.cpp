#include<iostream>

int main()

{
	int a1[10][10],a2[10][10],a3[10][10];
	int i1,i2,i3,j1,j2,j3;
	
	int x,y;
	
	std::cout<<"\n enter the dimensions of matrix 1   (i1,j1) max (10,10)";
	std::cin>>i1>>j1;
	
	std::cout<<"\n enter dimensions of matrix 2 (i2,j2) max(10,10)";
	std::cin>>i2>>j2;
	
	std::cout<<"\nenter contents of matrix1";
	for(x=0;x<i1;x++)
	{
		for(y=0;y<j2;y++)
		{
			std::cin>>a1[x][y];
			
		}
	}

    std::cout<<"\n enter the contents of matrix 2";
    
    for(x=0;x<i2;x++)
    {
    	for(y=0;y<j2;y++)
    	{
    		std::cin>>a2[x][y];
    		
    	}
    }
  /*
  
  
     if ((i1==i2)&&(j1==j2)
  {
  	std::cout<<"\n addition possible"; 
  	
  	
  	code for addition and subtraction
  	
  	
  	for(x=0;x<i1;x++)
  	{
  		for(y=0;y<j1;y++)
  		{
  			a3[x][y]=a1[x][y]-
			a2[x][y];
  		}
  	}
  	std::cout<<"\n the matrix is \n";
  	for(x=0;x<i1;x++)
  	{
  		for(y=0;y<j1;y++)
  		{
  			std::cout<<a3[x][y]<<"\t";
  		}
  	}
  	
  }
  else 
  std::cout<<"\n addition not possible";
  */
}
