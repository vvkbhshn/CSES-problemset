//problem link: https://cses.fi/problemset/task/1746/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int N,M;

int solve(int n, int m, vector<int> &arr, vector<vector<int>> &dp){
	if(m<1 || m>M) return 0; 
	if(n==0) return 1;
	if(dp[n][m]!=-1) return dp[n][m];
	int res=0;
	if(arr[n-1]>0){
		//value is fixed at index (n-1).
		if(abs(m-arr[n-1])<=1) res=solve(n-1,arr[n-1],arr,dp);
	}
	else{
		//value is not fixed, it depends in adjacent elements.
		res=(res+solve(n-1,m-1,arr,dp))%mod;
		res=(res+solve(n-1,m,arr,dp))%mod;
		res=(res+solve(n-1,m+1,arr,dp))%mod;
	}
	return dp[n][m]=res;
}


int main(){
	cin>>N>>M;
	vector<int> arr(N);
	for(int i=0;i<N;i++) cin>>arr[i];
	vector<vector<int>> dp(N+1, vector<int> (M+1,-1));
	int res=0;
	if(arr[N-1]==0) for(int i=1;i<=M;i++) res=(res+solve(N-1,i,arr,dp))%mod;
	else res=solve(N-1,arr[N-1],arr,dp);	
	cout<<res;
	return 0;
}