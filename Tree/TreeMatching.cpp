//problem link: https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+1;

int dp[N][2];
vector<int> adj[N];

void dfs(int u, int parent){
	dp[u][0]=0;
	dp[u][1]=0;
	bool leaf=1;
	for(auto v:adj[u]){
		if(v!=parent){
			leaf=0;
			dfs(v,u);
		}
	}
	if(leaf) return;
	vector<int> prefix, suffix;
	for(auto v:adj[u]){
		if(v!=parent){
			prefix.push_back(max(dp[v][0],dp[v][1]));
			suffix.push_back(max(dp[v][0],dp[v][1]));
		}
	}
	int m=prefix.size();
	for(int i=1;i<m;i++) prefix[i]+=prefix[i-1];
	for(int i=m-2;i>=0;i--) suffix[i]+=suffix[i+1];
	//dp[u][0] -> u in not matched with any of its child
	dp[u][0]=prefix[m-1];
	//dp[u][1] -> u is matched with one of its child, check for all 'm' children
	int i=0;
	for(auto v:adj[u]){
		if(v!=parent){
			int left=(i==0)?0:prefix[i-1];
			int right=(i==m-1)?0:suffix[i+1];
			dp[u][1]=max(dp[u][1],left+(1+dp[v][0])+right);
			i++;
		}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	cout<<max(dp[1][0],dp[1][1]);	
	return 0;
}