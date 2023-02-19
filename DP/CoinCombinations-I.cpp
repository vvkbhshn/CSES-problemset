#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){
	int n, x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int dp[x+1]={0};
	dp[0]=1;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=n;j++){
			if(i>=arr[j-1]) dp[i]=(dp[i]+dp[i-arr[j-1]])%mod;
		}
	}
	cout<<dp[x];
	return 0;
}
