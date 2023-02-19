#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){
	int n, x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int dp[x+1];
	dp[0]=0;
	for(int i=1;i<=x;i++) dp[i]=INT_MAX-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j>=arr[i-1]) dp[j]=min(dp[j], 1+dp[j-arr[i-1]]);
		}
	}
	if(dp[x]==INT_MAX-1) cout<<-1;
	else cout<<dp[x];
	return 0;
}
