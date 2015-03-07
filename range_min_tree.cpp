#include <stdio.h>
#include <limits.h>
 
#include <iostream>
#include <vector>
 
using namespace std;
 
int m(int a, int b){return a < b ? a : b;}
int M(int a, int b){return a < b ? b : a;}
 
class RmMQ{ // range minimum or maximum query
public:
	int n;
	vector <int> rangeMin, rangeMax;
	RmMQ(const vector<int> &arr, int flag){
		n = arr.size();
		rangeMin.resize(n*4);
		rangeMax.resize(n*4);
		init(arr, 1, n, 1, flag);
	}
 
	int init(const vector<int> &arr, int L, int R, int node, int flag){
		if(L==R){
			if(flag)return rangeMin[node] = arr[L];
			else
				return rangeMax[node] = arr[L];
		}
		int mid = (L+R) / 2;
		if(flag){
			int leftMin = init(arr, L, mid, node*2, flag);
			int rightMin = init(arr, mid+1, R, node*2+1, flag);
			return rangeMin[node] = m(leftMin, rightMin);
		}else{
			int leftMax = init(arr, L, mid, node*2, flag);
			int rightMax = init(arr, mid+1, R, node*2+1, flag);
			return rangeMax[node] = M(leftMax, rightMax);
		}
	}
 
	int query(int L, int R, int node, int nodeL, int nodeR, int flag){
		if(R < nodeL || nodeR < L){
			if(flag)return INT_MAX;
			else
				return INT_MIN;
		}
		if(L <= nodeL && nodeR <= R){
			if(flag)return rangeMin[node];
			else
				return rangeMax[node];
		}
 
		int mid = (nodeL + nodeR) / 2;
		if(flag)return m(query(L, R, node*2, nodeL, mid, flag), query(L, R, node*2+1, mid+1, nodeR, flag));
		else
			return M(query(L, R, node*2, nodeL, mid, flag), query(L, R, node*2+1, mid+1, nodeR, flag));
	}
	int query(int L, int R, int flag){
		return query(L, R, 1, 1, n, flag);
	}
};
 
int main()
{
	vector <int> input;
 
	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);
 
	input.resize(n);
	for(int i=0; i<n; i++){
		scanf("%d", &input[i]);
	}
 
	RmMQ tr(input, 1); // minimum
	tr.init(input, 1, n, 1, 0); // maximum
 
	bool f = false;
 
	for(int i=1; i<=n-m+1; i++){
		printf("%d %d\n", tr.query(i, i+m-1, 0), tr.query(i, i+m-1, 1));
		if(tr.query(i, i+m-1, 0) - tr.query(i, i+m-1, 1) <= c){
			f = true;
			printf("%d\n", i);
		}
	}
 
	if(!f)printf("NONE\n");
 
	return 0;
}


 
 input
7 2 0
0 1 1 2 3 2 2
  output
1 1
1
2 1
3 2
3 2
2 2
5
121 2
