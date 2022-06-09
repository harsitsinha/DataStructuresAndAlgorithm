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


int main(){
	fastio();
	vector<int> wt = {10,20,30};
	vector<int> val = {60,100,120};
	int n = wt.size();
	cout<<knapsack(wt,val,50,n);






	
}





