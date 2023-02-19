//problem link: https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){
	int n;
	cin>>n;
	int dp[n+1]={0};
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++) if(i>=j) dp[i]=(dp[i]+dp[i-j])%mod;
	}
	cout<<dp[n];
}
