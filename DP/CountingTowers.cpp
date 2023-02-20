//problem link: https://cses.fi/problemset/task/2413/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;		
		ll dp[n+1][2];
		dp[1][0]=dp[1][1]=1;
		for(int i=2;i<=n;i++){
			dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%mod; //last block is [    ]
			dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%mod; //last block is [ ][ ]
		}
		cout<<(dp[n][0]+dp[n][1])%mod<<'\n';
	}
	return 0;
}