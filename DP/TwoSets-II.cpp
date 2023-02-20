//problem link: https://cses.fi/problemset/task/1093/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

ll binpow(ll a, ll b, int m){
	a%=mod;
	ll res=1;
	while(b>0){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	int sum=(n*(n+1))/2;
	if(sum%2==0){
		sum/=2;
		int dp[sum+1]={0};
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=i;j--){
				dp[j]=(dp[j]+dp[j-i])%mod;
			}
		}
		//divide dp[sum] by 2. 
		// Use fermat's little theorem to compute multiplicative inverse of 2 % 1e9+7.
		cout<<(dp[sum]*binpow(2,mod-2,mod))%mod;
	}
	else cout<<0;
	return 0;
}