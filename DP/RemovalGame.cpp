//problem link: https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll dp[n][n];
	for(int i=0;i<n;i++){
		dp[i][i]=arr[i];
		if(i<n-1) dp[i][i+1]=max(arr[i],arr[i+1]);
	}
	for(int k=2;k<n;k++){
		for(int i=0;i<n-k;i++){
			int j=i+k;
			dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
						 arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
		}
	}
	cout<<dp[0][n-1];
	return 0;
}