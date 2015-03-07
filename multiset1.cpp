#include<iostream>
#include<vector>


int main()
{
	
	
	int num,temp;
	
	std::vector<int> hello;
		
	
	temp=5;
	while(temp--)
	{
		std::cin>>num;
		hello.push_back(num);
	}
	
	hello.remove(10);
	
	for(i=0;i<hello.size();i++)
    {
    	cout<<hello[i]<<"\n";
    	
    }
	
	
}
