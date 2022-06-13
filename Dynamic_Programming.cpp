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

int knapsack_tab(vector<int> wt, vector<int> val, int w, int n){
	int dp[n+1][w+1];
	for (int i = 0; i <=n; i++)
	{
		for(int j =0;j<=w;j++)
			if(i==0||j==0) dp[i][j]=0;
	}
	for(int i =1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(wt[i-1]<=j){
				dp[i][j]= max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][w];
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
	for(int i =0;i<=m;i++){
		dp[i][0]=0;
	}
	for(int i =0;i<=n;i++){
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
// Coin Change
int getCount_rec(int coins[],int n,int sum){
	if(sum==0) return 1;
	if(n==0) return 0;
	int res = getCount_rec(coins,n-1,sum);
	if(coins[n-1]<=sum){
		res+=getCount_rec(coins,n,sum-coins[n-1]);
	}
	return res;
}
// Coin Change
int getCount_tab(int coins[],int n , int sum){
	int dp[sum+1][n+1];
	for(int i=0;i<=n;i++){dp[0][i]=1;}
	for(int i=1;i<=sum;i++){dp[i][0]=0;}
	for(int i =1;i<=sum;i++){
		for(int j =1;j<=n;j++){
			dp[i][j]=dp[i][j-1];
			if(coins[j-1]<=i)
				dp[i][j]+=dp[i-coins[j-1]][j];
		}
	}
	return dp[sum][n];

}

int eD(string s1, string s2, int m, int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
        
    if(s1[m-1]==s2[n-1])
        return eD(s1,s2,m-1,n-1);
    else
    {
        return 1 + min(eD(s1,s2,m,n-1), min(eD(s1,s2,m-1,n), eD(s1,s2,m-1,n-1)));
    }
    
}

int eD_dp(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }
    
    for(int j=0;j<=n;j++)
    {
        dp[0][j]=j;
    }
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                
            }
        }
    }
    
    return dp[m][n];
    
}
//Longest increasing subsequence using DP
int LIC(vector<int> arr,int n){
	int dp[n];
	dp[0]=1;
	for(int i =1;i<n;i++){
		dp[i]=1;
		for(int j =0;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}

		}
	}
	int res = INT_MIN;
	for(int i =0;i<n;i++){
		res = max(res,dp[i]);
	}
	return res;

}
//Longest increasing subsequence using Binary Search
int ceilIndex(vector<int> tail, int l, int r, int x){

	while(l<r){
		int mid = l+(r-l)/2;
		if(tail[mid]==x) return mid;
		else if(tail[mid]>=x) r=mid;
		else{
			l = mid+1;
		}

	}
	return 0;
}
int LIC_binary_search(vector<int> arr, int n){
	vector<int> tail;
	tail.push_back(arr[0]);
	int len =1;
	for(int i =1;i<n;i++){
		if(arr[i]>arr[i-1]) {tail.push_back(arr[i]);len++;}
		else{
			int in = ceilIndex(tail, 0, len-1, arr[i]);
			tail[in] = arr[i];
		}
	}
	return len;
}

//Minimum deletion to make the array sorted here binary search used
int Min_del_sorted(vector<int> arr, int n){
	vector<int> tail;
	tail.push_back(arr[0]);
	int len =1;
	for(int i =1;i<n;i++){

			if(arr[i]>arr[i-1]) {
			tail.push_back(arr[i]);
			len++;
		}
		else{
			int in = ceilIndex(tail, 0, len-1, arr[i]);
			tail[in]= arr[i];

		}
		
		
	}
	return n-len;
}

//Maximum sum Increasing Subsequence
int Max_sum_LIC(vector<int> arr, int n){
	int dp[n];
	dp[0]=arr[0];
	for(int i =1;i<n;i++){
		dp[i]=arr[i];
		for(int j =0;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i]=max(dp[i],dp[j]+arr[i]);
			}

		}
	}
	int res =arr[0];
	for(int i =0;i<n;i++){
		res= max(res,dp[i]);
	}
	return res;

}

//Maximum Length Bitonic Subsequnce
int Max_bitonic_subseq(vector<int> arr,int n){
	int lic[n];
	int lds[n];
	lic[0]=1;
	lds[n-1]=1;
	for(int i =0;i<n;i++){
		lic[i]=1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				lic[i]= max(lic[i],lic[j]+1);

			}
		}
	}
	for(int i =n-2;i>=0;i--){
		lds[i]=1;
		for(int j =n-1;j>i;j--){
			if(arr[j]<arr[i])
			lds[i]= max(lds[i],lds[j]+1);
		}
	}
	int res[n];
	for(int i =0;i<n;i++){
		res[i]=lic[i]+lds[i]-1;

	}
	
	int result = 1;
	for(int i =0;i<n;i++){
		result = max(result,res[i]);
	}
	return result;
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

	////0-1 KNAPSACK USING TABULATION
	// vector<int> wt = {10,20,30};
	// vector<int> val = {60,100,120};
	// int n = wt.size();

	// cout<<knapsack_tab(wt,val,50,n);

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
	// string str1 = "AXYZ";
	// string str2 = "BAZ";
	// int m = str1.length();
	// int n = str2.length();
	// cout<<lCA_tab(str1,str2,m,n);

	////COIN CHANGE (Count Comination)
	// int coins[] = {2,5,3,6};
	// int n =4;
	// int sum = 10;
	// cout<<getCount_tab(coins,n, sum);

	////EDIT DISTANCE using recursion
	// string str1= "CAT";
	// string str2= "CUT";
	// int n=3,m=3;
	// cout<<eD(str1,str2,m,n);

	////EDIT DISTANCE using DP
	// string str1= "CAT";
	// string str2= "CUT";
	// int n=3,m=3;
	// cout<<eD_dp(str1,str2,m,n);

	////Longest Increasing Subsequce LIC
	// vector<int> vec = {3,4,2,8,10,5,1};
	// cout<<LIC(vec,vec.size());

	////Longest Increasing Subsequce LIC using binary
	// vector<int> vec = {3,4,2,8,10,5,1};
	// cout<<LIC_binary_search(vec,vec.size());

	////Minimum deletion to make array sorted
	// vector<int> vec = {3,4,2,8,10,5,1};
	// cout<<Min_del_sorted(vec,vec.size());

    ////Maximum sum Increasing Subsequence
	// vector<int> vec = {3,4,2,8,10,5,1};
	// cout<<Max_sum_LIC(vec,vec.size());

	////Maximum Length Bitonic Subsequnce
	vector<int> vec = {1,11,2,10,4,5,2,1};
	cout<<Max_bitonic_subseq(vec,vec.size());


		





	
}





