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

struct Node{
	int key;
	struct Node * left;
	struct Node * right;
	Node(int k){
		key=k;
		left=right=NULL;
	}
};

Node* insert(Node *root, int x){
	if(root==NULL) {
		root = new Node(x);
		
		return root;
	};
	if(root->key>x){
		root->left  = insert(root->left,x);
	}
	else if(root->key<x)
		root->right  = insert(root->right,x);
	return root;
}

void print_levels_line2(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(q.empty()==false){
		
		int count = q.size();
		for(int i =0;i<count;i++){
			Node *curr = q.front();
			cout<<curr->key<<" ";
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
			q.pop();
		}
		cout<<endl;
	}
}
bool search(Node* root, int x){
	if(root==NULL) return false;
	if(root->key==x)return true;
	else if(root->key>x)
		return search(root->left,x);
	else if (root->key<x)
		return search(root->right,x);
	return false;
}
Node * getSuccessor(Node * curr){
	curr = curr->right;
	while(curr->left!=NULL && curr!=NULL)
		curr=curr->left;
	return curr;
}

Node * deletNode(Node *root, int x){
	if(root==NULL) return root;
	if(root->key>x)
		root->left = deletNode(root->left,x);
	else if(root->key<x)
		root->right = deletNode(root->right,x);
	else{
		if(root->left==NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}
		if(root->right==NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node *succ = getSuccessor(root);
			root->key = succ->key;
			root->right = deletNode(root->right,succ->key);
		}
	}
	return root;
}
Node* floorNode(Node *root, int x){

	Node *res = NULL;
	while(root!=NULL){
		if(root->key==x)
			return root;
		else if(root->key>x)
			root=root->left;
		else{
			res= root;
			root=root->right;
		}
	}
	return res;
}

Node* ceilNode(Node *root, int x){
	Node *res = NULL;
	while(root!=NULL){
		if(root->key==x)
			return root;
		else if(root->key>x){
			res = root;
			root=root->left;
		}
		else{
			
			root=root->right;
		}
	}
	return res;
}

int main(){
	fastio();

	//insertion in Binary Search Tree
	vector<int> arr = {20,15,30,40,50,12,18,35,80,7};
	Node *root = new Node(20);
	for(int i =1;i<arr.size();i++){
		insert(root,arr[i]);
	}
	// print_levels_line2(root);
	
	//search in Binary Search Tree
	// if(search(root,9)) cout<<"YES";
	// else cout<<"N0";

	//Binary Search Tree Deletion
	// Node * curr = deletNode(root,20);
	// print_levels_line2(curr);

	//Binary Search Tree Floor and Ceil
	Node *floor_val = ceilNode(root,7);
	cout<<floor_val->key;

}









