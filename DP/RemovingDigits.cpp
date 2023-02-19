//problem link: https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &dp){
	if(i==0) return 0;
	if(dp[i]!=-1) return dp[i];
	vector<int> digits;
	int j=i;
	while(j>0){
		if(j%10) digits.push_back(j%10);
		j/=10;		
	} 
	int res=INT_MAX;
	for(auto j:digits){
		if(i>=j) res=min(res,1+solve(i-j,dp));
	}
	return dp[i]=res;
}

int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1, -1);
	cout<<solve(n,dp);
	return 0;
}
