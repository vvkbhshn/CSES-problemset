#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int main(){
	int n;
	cin>>n;
	char maze[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>maze[i][j];	
	if(maze[0][0]=='.' && maze[n-1][n-1]=='.'){
		int dp[n];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;i++){
			if(maze[i][0]=='*') dp[0]=0;
			for(int j=1;j<n;j++){
				if(maze[i][j]=='*') dp[j]=0;
				else dp[j]=(dp[j-1]+dp[j])%mod;
			}
		}		
		cout<<dp[n-1];
	}
	else cout<<0;
	return 0;
}
