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
///////////////Creating ADJENCY LIST/////////
void addEdge(vector<int> adj[],int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V){
	for(int i =0;i<V;i++){
		for(int x:adj[i])
			cout<<x<<" ";
		cout<<"\n";
	}
}
//////////////////////////////////////////////

///////////////  BFS   ///////////////////////
void BFS(vector<int> adj[], int V, int s){
	bool visited[V];
	for(int i =0;i<V;i++){
		visited[i] = false;

	}
	queue<int> q;

	visited[s] = true;
	q.push(s);
	while(q.empty()==false){
		int u = q.front();
		q.pop();
		cout<<u<<" ";
		// cout<<"SIZE "<<q.size();
		cout<<endl;
		for(int v:adj[u]){
			if(visited[v]==false){
				visited[v]=true;
				q.push(v);
				// cout<<v;
			}
		}
		// cout<<endl;
	}
}


void BFS_(vector<int> adj[], int s, bool visited[]){
	
	queue<int> q;

	visited[s] = true;
	q.push(s);
	while(q.empty()==false){
		int u = q.front();
		q.pop();
		cout<<u<<" ";
		// cout<<"SIZE "<<q.size();
		// cout<<endl;
		for(int v:adj[u]){
			if(visited[v]==false){
				visited[v]=true;
				q.push(v);
				// cout<<v;
			}
		}
		// cout<<endl;
	}
}

int BFSDin(vector<int> adj[], int V){
	bool visited[V];
	int count=0;
	for(int i =0;i<V;i++){
		visited[i] = false;

	}
	for(int i =0;i<V;i++){
		if(visited[i]==false){
			BFS_(adj,i,visited);
			count++;
		}

	}
	cout<<endl;
	return count;
}

void DFSRec(vector<int> adj[], int s, bool visited[])
{
	visited[s] = true;
	cout<<s<<" ";
	for(int u:adj[s]){
		if(visited[u]==false)
			DFSRec(adj,u,visited);
	}
}
void DFS(vector<int> adj[], int V, int s){
	bool visited[V];
	for(int i =0;i<V;i++){
		visited[i]=false;

	}
	DFSRec(adj,s,visited);
}

int main(){
	fastio();
	// int V= 4;
	// vector<int> adj[V];
	// addEdge(adj,0,1);
	// addEdge(adj,0,2);
	// addEdge(adj,1,2);
	// addEdge(adj,1,3);
	

	// printGraph(adj, V);
	// return 0;

	// int V=6;
	// vector<int> adj[V];
	// addEdge(adj,0,1); 
	// addEdge(adj,0,2); 
	// addEdge(adj,1,2); 
	// addEdge(adj,2,3); 
	// addEdge(adj,1,3);
	// addEdge(adj,3,4);
	// addEdge(adj,2,4);
	// addEdge(adj,4,5);


	// BSF(adj,V,0);

	// int V=7;
	// vector<int> adj[V];
	// addEdge(adj,0,1); 
	// addEdge(adj,0,2); 
	// addEdge(adj,2,3); 
	// addEdge(adj,1,3); 
	// addEdge(adj,4,5);
	// addEdge(adj,5,6);
	// addEdge(adj,4,6);

	// cout<<BFSDin(adj,V); 

	int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,1,4);
	addEdge(adj,3,4);
	// printGraph(adj, V);
	// cout << "Following is Depth First Traversal: "<< endl;
	DFS(adj,V,0);


}







