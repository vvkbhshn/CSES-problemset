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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j>=arr[i-1]) dp[j]=(dp[j]+dp[j-arr[i-1]])%mod;
		}
	}
	cout<<dp[x];
	return 0;
}
