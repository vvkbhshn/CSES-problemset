//problem link: https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int arr[n], sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	bool dp[2][sum+1];
	memset(dp,false,sizeof(dp));
	dp[0][0]=dp[1][0]=true;
	int idx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=arr[i-1]) dp[idx][j] = dp[1-idx][j] || dp[1-idx][j-arr[i-1]];
			else dp[idx][j] = dp[1-idx][j];
		}
		idx=1-idx;
	}
	idx=1-idx;	
	vector<int> res;
	for(int i=1;i<=sum;i++) if(dp[idx][i]) res.push_back(i);
	cout<<res.size()<<'\n';
	for(auto x:res) cout<<x<<" ";
	return 0;
}