void merge_sort(int a[],int n)
{
	int i,j;
	int from=0,mid=(n/2)-1,to=n-1;
 
	for(i=n; i>1; i /= 2)
	{
		for(j=0; j<=n-1; j += i)
		{
          from = j;
          to = j+i-1;
		  mid = (from + to)/2;
 
		display(a,from,mid,to);
          //merge(a,from,mid,to);
		}
 
	}
	
	
	
	
	
	
	
	void merge(int a[],int low,int mid,int high)
{
	int temp[16] = {0};
	int l = low,h = high, m = mid+1;
	int i,k;
 
    i = l;
 
	while((l<=mid) && (m<=h))
	{
 
		if(a[l]<=a[m])
		{
			temp[i] = a[l];
			l++;
		}
		else
		{
			temp[i] = a[m];
			m++;
		}
		i++;
	}
	if(mid>=l)
	{
		for(k=l; k<=mid; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
	else if(high>=m)
	{
		for(k=m; k<=high; k++)
		{
			temp[i] = a[k];
			i++;
		}
	}
 
	for( k=low; k<=high; k++)
	{
		a[k] = temp[k];
	}
}
