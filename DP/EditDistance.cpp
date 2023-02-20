//problem link: https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	string a,b;
	cin>>a>>b;
	int m=a.length(), n=b.length();
	if(m<n){
		swap(a,b);
		swap(m,n);
	}
	int dp[n+1];
	for(int i=0;i<=n;i++) dp[i]=i;
	for(int i=1;i<=m;i++){
		int prev2=0, prev=dp[0];
		dp[0]=i;
		for(int j=1;j<=n;j++){
			prev2=prev;
			prev=dp[j];
			if(a[i-1]==b[j-1]) dp[j]=prev2;
			else dp[j]=1+min(prev2,min(dp[j],dp[j-1]));		
			// if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
			// else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	cout<<dp[n];
	return 0;
}