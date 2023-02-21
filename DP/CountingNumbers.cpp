//problem link: https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;


ll dp[20][10][2][2];

ll solve(string &s, int n, int prev, int leadingZeros, int tight){
	if(n==0) return 1;
	if(dp[n][prev][leadingZeros][tight]!=-1) return dp[n][prev][leadingZeros][tight];
	ll res=0;
	int currDigit=s[s.length()-n]-'0';
	int upperBound = tight ? currDigit : 9;
	for(int digit=0; digit<=upperBound; digit++){
		if(digit==prev && leadingZeros==0) continue;
		res+=solve(s,n-1,digit, leadingZeros && (digit==0), tight && (digit==upperBound));
	}
	return dp[n][prev][leadingZeros][tight]=res;
}

int main(){
	ll a,b;
	cin>>a>>b;
	a--;
	string A=to_string(a);
	string B=to_string(b);
	ll ans1=0, ans2=0;
	memset(dp,-1,sizeof dp);
	ans1=solve(B,B.length(),0,1,1);
	memset(dp,-1,sizeof dp);
	if(a>=0) ans2=solve(A,A.length(),0,1,1);
	cout<<ans1-ans2;	
	return 0;
}