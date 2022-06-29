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
bool islss(int num, int check){
	int ans =0;
	int two = 2;
	int count =0;
	while(num>0){
		int d = num%10;
		ans += pow(2,count++)*d;
	}
	cout<<ans<<endl;
	return ans<=check;
}
void func(string t, int i, int n, string s, int num, vector<int> &ans){
	if(i==n) {
		if(islss(stoi(t),num))
			ans.push_back(stoi(t));
	}
	else{
		func(t,i+1,n,s, num,ans);
		t+=s[i];
		func(t,i+1,n,s, num,ans);


	}

}
bool isAnangram(string a, string b){
    if(a.length()!=b.length()) return false;
   unordered_map<char,int> m;
   unordered_map<char,int> mm;
   int n = a.length();
   for(int i =0;i<n;i++){
       m[a[i]]++;
   } 
   for(int i =0;i<n;i++){
       mm[b[i]]++;
   }
   for(auto x:m){
       if(mm.find(x.first)==mm.end()) return false;
       else{
           if(mm[x.first]!=x.second) return false;
       }
       
   }
   return true;
   
   
}
vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int>> ans;
    int n = A.size();
    unordered_set<int> check;
    for(int i =0;i<n;i++){
        vector<int> subans;
        if(check.find(i+1)==check.end()) {subans.push_back(i+1);}
        else continue;
        for(int j =i+1;j<n;j++){
            if(isAnangram(A[i],A[j])){
                subans.push_back(j+1);
                check.insert(j+1);
                // cout<<"j"<<j+1<<" ";
            }
        }
        if(subans.empty()==false) ans.push_back(subans);
    }
    return ans;
}
int solve(vector<int> &A, int B) {
    vector<int> C;
    for(auto x:A){
        C.push_back(x%2);   
    }
    unordered_map <int,int> m;
    int presum =0;
    int count =0;
    for(int i =0;i<A.size();i++){
        presum+=C[i];
        if(presum==B) {cout<<"pre"<<presum<<endl;count++;}
        if(m.find(presum-B)!=m.end()){
        	cout<<presum<<"presum"<<m[i-B]<<endl;
            count+=m[i-B];
        }
        m[presum]++;
    }
    // for(auto x:m){
    // 	cout<<x.first<<" "<<x.second<<endl;
    // }
    return count;
}
bool comp(vector<int>a, vector<int>b){
    int r1 = a.back()-a[0];
    int r2 = b.back()-b[0];
    if (r1==r2) return a[0]<b[0];
    return r1>r2;
}
vector<int> lszero(vector<int> &A) {
    unordered_map<int,int> m;
    int n =A.size();
    int prefix =0;
    unordered_map<int,vector<int>> ma;
    vector<vector<int>> ans;
    for(int i =0;i<n;i++){
        prefix += A[i];

        if(prefix==0) {
            // vector<int> temp = {-1,i}
            ma[-1].push_back(-1);
            ma[-1].push_back(i);
        }
        if(m.find(prefix)==m.end()){
            m.insert({prefix,i});
            // cout<<prefix<<endl;
        }
        else{
            if(ma.find(prefix)==ma.end()&&m.empty()==false){
                ma[prefix].push_back(m[prefix]);
                ma[prefix].push_back(i);
            }
            else if (m.empty()==false){
                ma[prefix].push_back(i);
            }
        }
    }
    cout<<ma.size()<<endl;
    if(ma.empty()==true) return {};
    for(auto x:ma){
        ans.push_back(x.second);
    }
    sort(ans.begin(),ans.end(),comp);
    vector<int> B;
    for(int i = ans[0][0]+1;i<=ans[0].back();i++){
        B.push_back(A[i]);
    }
    return B;
}
int isValidSudoku(const vector<string> &A) {
    // checking for valid row
    int n = A.size(); 
    for(int i =0;i<n;i++){
        unordered_set<char> s;
        int count =0;
        for(int j =0;j<n;j++){
            if(A[i][j]=='.') continue;
            else{
            s.insert(A[i][j]);
            count++;    
            }
        }
        if(count!=s.size()) return 0;
        else cout<<i<<" i row valid"<<endl;
    }
    for(int i =0;i<n;i++){
        unordered_set<char> s;
        int count =0;
        for(int j =0;j<n;j++){
            if(A[j][i]=='.') continue;
            else{
            s.insert(A[j][i]);
            count++;    
            }
        }
        if(count!=s.size()) return 0;
        else cout<<i<<" j column valid"<<endl;
    }
    int k =0;
    int l=0;
    int N =(int)sqrt(n);
    while(k<n){
        
        
        l=0;
            while(l<n){
            	int count =0;
            	unordered_set<char> s;
            for(int i=0+k;i<N+k;i++){
                 
                for(int j =0+l;j<N+l;j++){
                    if(A[i][j]=='.') continue;
                    else{
                    s.insert(A[i][j]);
                    count++;    
                    }
                }
                
                
            }
            // cout<<l<<" j row valid"<<endl;
            if(count!=s.size()) {return 0;}
            l+=N;
        }
            
        
        
        // cout<<k<<" i row valid"<<endl;
        k+=N;
    }
    return 1;
}

string fractionToDecimal(int A, int B) {
    return to_string(A*1.0/B);
}


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 void inorder(TreeNode * root, vector<int> &ans){
     if(root != NULL){
         inorder(root->left,ans);
         ans.push_back(root->val);
         inorder(root->right,ans);
     }
}
bool search(TreeNode *root, int x){
    if(root = NULL) return false;
    if(root->val==x) return true;
    else if(root->val>x) return search(root->left,x);
    else if(root->val<x) return search(root->right,x);
    else return false;
}
int t2Sum(TreeNode* A, int B) {
    vector<int> ans;
    inorder(A,ans);
    int n = ans.size();
    for(int i=0;i<n;i++){
        if(search(A,B-ans[i]) && (ans[i]!=(B-ans[i]))) return 1;
    }
    return 0;
}

int main(){
	fastio();
	TreeNode * root = new TreeNode(7);
	root->right = new Node(10);
	root->right->left = new Node(9);
	root->right->right = new Node(20);
	cout<<t2Sum(root, 19);	

}