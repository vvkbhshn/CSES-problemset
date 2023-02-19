//problem link: https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	int price[n], pages[n];
	for(int i=0;i<n;i++) cin>>price[i];
	for(int i=0;i<n;i++) cin>>pages[i];
	int dp[x+1]={0};
	for(int i=1;i<=n;i++){
		for(int j=x;j>=price[i-1];j--){
			dp[j]=max(dp[j], pages[i-1]+dp[j-price[i-1]]);
		}
	}
	cout<<dp[x];
	return 0;
}
