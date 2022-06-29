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

//printing all the permutation
void permutate(string str, int l, int level){
	if(l==level) {
		cout<<str<<endl;

	}
	for(int i =l;i<=level;i++){
		swap(str[i],str[l]);
		permutate(str,l+1,level);
		swap(str[i],str[l]);
	}
}

//printing all the permutation which not contain AB
void permutate_AB(string str, int l, int level){
	if(l==level) {
		if(str.find("AB")==string::npos)
			cout<<str<<endl;
		return;
	}
	for(int i =l;i<=level;i++){
		swap(str[i],str[l]);
		permutate_AB(str,l+1,level);
		swap(str[i],str[l]);
	}
}

//printing all the permutation which not contain AB using Backtracking
bool isSafe(string str,int i, int l,int level){
	if(l!=0 && str[l-1]=='A' && str[i]=='B') return false;
	if(level==(l+1) && str[l]=='B' && str[i]=='A') return false;
	return true;
}
void permutate_AB_backtracking(string str, int l, int level){
	if(l==level) {
		cout<<str<<endl;
		return;
	}
	for(int i =l;i<=level;i++){
		if(isSafe(str,i,l,level)){
			swap(str[i],str[l]);
			permutate_AB(str,l+1,level);
			swap(str[i],str[l]);
		}
		
	}
}

//rat in maze
bool isSafe_maze(vector<vector<int>> maze, int i,int j,int n){
	if(i>=n ||j>=n) return false;
	if(maze[i][j]==0) return false;
	return true;

}
int canPass(vector<vector<int>> maze, int i,int j,int n){
	if(i==n-1 && j==n-1)
		return 1;
	cout<<i<<" "<<j<<endl;
	if(isSafe_maze(maze,i+1,j,n)||isSafe_maze(maze,i,j+1,n))
		return max(canPass(maze,i+1,j,n),canPass(maze,i,j+1,n));
	
	return -1;

}
int jj=0
int n=4;
int arr[n][n];
bool isSafe_N_Queen(arr[][],int i,int j,int n){

}

bool N_Queen(arr[][],int i,int j,int n){
	if(i==n) return true;
	if(j>=n) {
		memset(arr, 0, sizeof(arr));
		return N_Queen(arr,0,jj+1,n)
	}
	if(isSafe_N_Queen(arr,i,j,n) ) {
		arr[i][j]=1;
		return N_Queen(arr,i+1,j,n);
	}
	else(N_Queen(arr,i,j+1,n)==true)


}

int main(){
	fastio();
	////printing all the permutations
	// permutate("ABC",0,2);

	////printing all the permutations without AB
	// permutate_AB("ABC",0,2);

	////printing all the permutations without AB backtracking
	// permutate_AB_backtracking("ABC", 0, 2);

	////rat in maze
	// vector<vector<int>> maze = {{1,0,0,0},{1,1,0,0},{0,1,0,0},{1,1,1,1}};
	// vector<vector<int>> maze = {{1,0,1},{1,1,0},{0,1,1}};
	// vector<vector<int>> maze = {{1,0,0},{0,1,0},{1,1,1}};
	// cout<<canPass(maze,0,0,maze.size());

	////N_Queen
	
	memset(arr,0,sizeof(arr));
	if(N_Queen(arr,0,jj,n)) cout<<"YES";
	else cout<<"NO";
	// for(int i =0;i<n;i++){
	// 	for(int j =0;j<n;j++){
	// 		cout <<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }











}