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

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	Node(int k){
		key = k;
		left = right = NULL;
	}

};
void inorder(Node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}
void preorder(Node *root){
	if(root!=NULL){
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
}
int height(Node *root){
	if(root==NULL) return 0;
	else return (max(height(root->left),height(root->right))+1);
}
void print_nodes(Node *root, int height, int k){
	if(root==NULL) return;
	if(height ==k){
		cout<<root->key<<" ";
		return;
	}
	else{
		print_nodes(root->left,height+1,k);
		print_nodes(root->right,height+1,k);

	}
}
void print_levels(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(q.empty()==false){
		Node *curr;
		curr= q.front();
		q.pop();
		cout<<curr->key<<" ";
		if(curr->left!=NULL){
			q.push(curr->left);
		}
		if(curr->right!=NULL){
			q.push(curr->right);
		}
	}
}
void print_levels_line(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node *curr = q.front();
		
		q.pop();
		if(curr==NULL){
			cout<<endl;
			q.push(NULL);
			continue;
		}
		cout<<curr->key<<" ";
		if(curr->left!=NULL) q.push(curr->left);
		if(curr->right!=NULL) q.push(curr->right);

	}
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
	}
}
int getSize(Node * root){
	if(root==NULL) return 0;
	return (1+getSize(root->left)+getSize(root->right));
}
int getMax(Node *root){
	if(root == NULL) return INT_MIN;
	return (max(root->key, max(getMax(root->left),getMax(root->right))));
}
void print_left(Node *root){
	if(root==NULL) return;
	queue<Node *> q;
	q.push(root);
	while(q.empty()==false){
		int count = q.size();
		for(int i=0;i<count;i++){
			Node *curr = q.front();
			q.pop();
			if(i==0) cout<<curr->key<<" ";
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
			
		}
	}
}
int maxLevel=0;
void print_left_recursive(Node *root,int level){
	if(root==NULL) return;
	if(maxLevel<level){
		cout<<(root->key)<<" ";
		maxLevel= level;

	}
	print_left_recursive(root->left,level+1);
	print_left_recursive(root->right,level+1);
}
bool children_sum(Node *root){
	if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return 1;
	int sum =0;
	if(root->left!=NULL) sum+=children_sum(root->left);
	if(root->right!=NULL) sum+=children_sum(root->right);
	return (sum==root->key&& children_sum(root->left)&& children_sum(root->right));
}
int maximum_width(Node *root){
	queue<Node *> q;
	q.push(root);
	int result=0;
	while(q.empty()==false){
		int count  = q.size();
		result= max(result,count);
		for (int i = 0; i < count; ++i)
		{
			// max_size++;
			Node *curr = q.front();
			q.pop();
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);

		}
		// result = max(max_size,result);
	}
	return result;
}
int preIndex =0;
Node *cTree(vector<int> in, vector<int> pre,int is,int ie )
{
	if(is>ie) return NULL;
	Node *root = new Node(pre[preIndex++]);
	int inIndex;
	for(int i =is;i<=ie;i++){
		if(in[i]==root->key){
			inIndex=i;
			break;
		}
	}
	root ->left = cTree(in,pre,is,inIndex-1);
	root ->right = cTree(in,pre,inIndex+1,ie);
return root;
}
void print_spiral(Node *root){
	queue<Node *> q;
	q.push(root);
	stack<int> s;
	bool reverse = false;
	while(q.empty()==false){
		int count = q.size();
		for (int i = 0; i < count; ++i)
		{
			/* code */
			Node *curr = q.front();
			q.pop();
			if(reverse){
				s.push(curr->key);
			}
			else{
				cout<<curr->key<<" ";
			}
			
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);

		}
		if(reverse){
			while(s.empty()==false){
				cout<<s.top()<<" ";
				s.pop();
			}
		}
		reverse=!reverse;
	}
}
void print_spiral_effecient(Node *root){
	if(root==NULL)
		return;
	stack<Node*>s1;
	stack<Node*>s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node *temp = s1.top();
			s1.pop();
			cout<<temp->key<<" ";

			if(temp->right)
				s1.push(temp->right);
			if(temp->left)
				s2.push(temp->left);

		}
	
		while (!s2.empty()) { 
            Node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->key << " "; 
  
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
    	} 
    }
}
int diameter(Node *root){
	if(root==NULL) return 0;
	int d1 = 1+height(root->left)+height(root->right);
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);
	return max(d1,max(d2,d3));
}
int res = 0;
int diameter_with_modified_height(Node *root){
	if(root==NULL) return 0;
	int lh = diameter_with_modified_height(root->left);
	int rh = diameter_with_modified_height(root->right);
	res = max(res, lh+rh+1);
	return 1+max(lh,rh);
}

//LCA
bool findPath(Node *root, vector<Node *> &p, int n){
	if(root==NULL) return false;
	p.push_back(root);
	if(root->key==n) return true;
	if(findPath(root->left,p,n)|| findPath(root->right,p,n)) return true;
	p.pop_back();
	return false;

}

//Lowest common ancestor
Node *LCA(Node *root, int n1,int n2){
	vector<Node *> path1, path2;
	if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
		return NULL;
	for(int i =0;i<path1.size()&&path2.size();i++){
		if(path1[i+1]!=path2[i+1])
			return path1[i];
	}
	return NULL;
}
// O(n) solution to lca
Node *lca(Node *root, int n1 , int n2){
	if(root==NULL) return NULL;
	if(root->key==n1||root->key ==n2)
		return root;
	Node * lca1 = lca(root->left,n1,n2);
	Node * lca2 = lca(root->right,n1,n2);
	if(lca1!=NULL && lca2!=NULL)
		return root;
	if(lca1!=NULL)
		return lca1;
	return lca2;
}
int main(){
	fastio();
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->right = new Node(60);
	root->left->right->left = new Node(70);
	root->left->right->right = new Node(80);

	// postorder(root);
	// cout<<height(root);
	// print_nodes(root,0,1);
	// print_levels_line2(root);
	// cout<<getMax(root);
	// print_left_recursive(root,1);
	// if(children_sum(root)) cout<<"yes";
	// else cout<<"No";
	// cout<<maximum_width(root);
	// vector<int> in ={20,10,40,30,50};
	// vector<int> pre ={10,20,30,40,50};
	// Node* result =cTree(in,pre,0,in.size()-1);
	// postorder(result);
	// print_spiral_effecient(root);
	
	// cout<<diameter_with_modified_height(root);
	// cout<<res;

	int n1 = 80, n2 = 30;
	cout<<lca(root,n1,n2)->key;
}

	








