//problem link: https://cses.fi/problemset/task/1674/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int dfs(int u, vector<int> &arr, vector<int> adj[]){
	int child=0;
	for(auto v:adj[u]) child+=1+dfs(v,arr,adj);
	return arr[u]=child;
}
 
int main(){
	int n;
	cin>>n;
	vector<int> adj[n+1];
	for(int i=0;i<n-1;i++){
		int num;
		cin>>num;
		adj[num].push_back(i+2);
	}
	vector<int> arr(n+1,0);
	dfs(1,arr,adj);
	for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	return 0;
}