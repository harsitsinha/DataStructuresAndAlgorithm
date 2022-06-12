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

int lCA(string str1,string str2, int m, int n){
	if(m==0||n==0) return 0;
	if(str1[m-1]==str2[n-1]) return 1+lCA(str1,str2,m-1,n-1);
	else 
		return max(lCA(str1,str2,m,n-1),lCA(str1,str2,m-1,n));

}
int lCA_memo(string str1,string str2, int m, int n){
	if(m==0||n==0) t[m][n]=0;
	if(str1[m-1]==str2[n-1]) {
		t[m][n]= 1+lCA_memo(str1,str2,m-1,n-1);
		return t[m][n];

	}
	else {
		t[m][n]= max(lCA_memo(str1,str2,m,n-1),lCA_memo(str1,str2,m-1,n));
		return t[m][n];
	}

}

int lCA_tab(string str1,string str2, int m, int n){
	int dp[m+1][n+1] ;
	memset(dp, -1, sizeof(dp));
	for(int i =0;i<m;i++){
		dp[i][0]=0;
	}
	for(int i =0;i<n;i++){
		dp[0][i]=0;
	}
	for(int i =1;i<=m;i++){
		for(int j=1;j<=n;j++){
			
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];

			}
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

			
				
		}
	}
	return dp[m][n];
}

int main(){
	fastio();
	////0-1 KNAPSACK
	// vector<int> wt = {10,20,30};
	// vector<int> val = {60,100,120};
	// int n = wt.size();
	// cout<<knapsack(wt,val,50,n);

	////0-1 KNAPSACK USING MEMOISATION
	// vector<int> wt = {10,20,30};
	// vector<int> val = {60,100,120};
	// int n = wt.size();
	// memset(t, -1, sizeof(t));
	// cout<<knapsack_memo(wt,val,50,n);

	////fibonaci using memoisation
	// memset(memo,-1,sizeof(memo));
	// cout<<fib(100);

	////fibonaci using tabulation
	// cout<<fibTabular(10);

	////Lowest common suqsequense using recursion
	// string str1 = "AXYZ";
	// string str2 = "BAZ";
	// int m = str1.length();
	// int n = str2.length();
	// cout<<lCA(str1,str2,m,n);



	////Lowest common suqsequense using memoization
	// string str1 = "AXYZ";
	// string str2 = "BAZ";
	// int m = str1.length();
	// int n = str2.length();
	// memset(t, -1, sizeof(t));
	// cout<<lCA_memo(str1,str2,m,n);


	////Lowest common suqsequense using tabulation
	string str1 = "AXYZ";
	string str2 = "BAZ";
	int m = str1.length();
	int n = str2.length();
	cout<<lCA_tab(str1,str2,m,n);





		





	
}





