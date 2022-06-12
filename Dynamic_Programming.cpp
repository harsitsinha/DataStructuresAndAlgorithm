#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <limits>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;

void fastio(){
	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);
}
//0/1 KNAPSACK
//There are n items to out in knapsack. Maximise the profit. 

int knapsack(vector<int> wt, vector<int> val, int weight, int n){

	if(n==0|| weight==0) return 0;

	if(wt[n-1]<=weight){
		return max(val[n-1]+knapsack(wt,val,weight-wt[n-1],n-1), knapsack(wt,val,weight,n-1));

	}
	else 
		return knapsack(wt,val,weight,n-1);
}

//0/1 KNAPSACK USING MEMOISATION
//There are n items to out in knapsack. Maximise the profit. 
int static t[100][100];
int knapsack_memo(vector<int> wt, vector<int> val, int weight, int n){

	if(n==0|| weight==0) return 0;
	if(t[n][weight]!=-1) return t[n][weight];

	if(wt[n-1]<=weight){
		t[n][weight] = max(val[n-1]+knapsack_memo(wt,val,weight-wt[n-1],n-1), knapsack_memo(wt,val,weight,n-1));
		return t[n][weight];

	}
	else 
		t[n][weight] = knapsack_memo(wt,val,weight,n-1);
		return t[n][weight];
}

int memo[1000000];
//using memoisation
int fib(int n){
	int res =0;
	if(memo[n]==-1){
		if(n==1||n==0){
			res = n;
		}
		else
			return fib(n-1)+ fib(n-2);
		memo[n] = res;
	}
	
	return memo[n];

}
//using tabulation
int fibTabular(int n){
	vector<int> f(n+1,-1);
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
	return f[n];

}

int main(){
	fastio();
	////0-1 KNAPSACK
	// vector<int> wt = {10,20,30};
	// vector<int> val = {60,100,120};
	// int n = wt.size();
	// cout<<knapsack(wt,val,50,n);

	////0-1 KNAPSACK USING MEMOISATION
	vector<int> wt = {10,20,30};
	vector<int> val = {60,100,120};
	int n = wt.size();
	memset(t, -1, sizeof(t));
	cout<<knapsack_memo(wt,val,50,n);
	////fibonaci using memoisation
	// memset(memo,-1,sizeof(memo));
	// cout<<fib(100);

	////fibonaci using tabulation
	// cout<<fibTabular(10);




		





	
}





