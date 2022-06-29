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
//
int minCoin(vector<int> coins,int n, int amount){

	sort(coins.begin(),coins.end(),greater<int>());
	int res =0;
	for(int i =0;i<n;i++){
		if(coins[i]<=amount){
			int c = floor(amount/coins[i]);
			res+=c;
			amount-=c*coins[i];
		}
		if(amount==0) break;
	}
	return res;
}
bool comp(pair<int,int> a,pair<int,int> b){
	return (a.second<b.second);
}

//activity selection
int activity_selction(vector<pair<int,int>> arr){
	int n = arr.size();
	int count =1;
	int prev=0;
	sort(arr.begin(),arr.end(),comp);

	for(int i =1;i<n;i++){
		if(arr[i].first>=arr[prev].second){
			count++;
			prev=i;
		}
	}
	return count;
}
bool comp_fknap(pair<int,int> a, pair<int,int> b){
	double r1 = a.first*0.1/a.second;
	double r2 = b.first*0.1/b.second;
	return r1>r2;

}
double fractional_knapsack(vector<pair<int,int>> arr, int weight){
	int n = arr.size();
	sort(arr.begin(),arr.end(),comp_fknap);
	double res =0.0;
	for(int i =0;i<n;i++){
		if(arr[i].second<=weight){
			res+= arr[i].first;
			weight-=arr[i].second;

		}
		else{
			res+=(weight)*arr[i].first*1.0/arr[i].second;
			break;
		}
	}
	return res;
}

int main(){
	fastio();
	////Min coins using greedy works in some cases
	// vector<int> coins = {5,10,2,1};
	// int n = 4;
	// int amount = 57;
	// cout<<minCoin(coins,n,amount);

	////activity selection
	// vector<pair<int,int>> arr = {{12,25},{10,20},{20,30}};
	// cout <<activity_selction(arr);

	////fractional knapsack
	vector<pair<int,int>> arr = {{120,30},{100,20},{60,10}};
	int weight = 50;
	cout<<fractional_knapsack(arr,weight);

}