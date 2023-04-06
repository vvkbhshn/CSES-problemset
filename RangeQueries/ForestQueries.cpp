//problem link: https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	char c;
	int numTrees[n+1][n+1];
	memset(numTrees,0,sizeof numTrees);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			if(c=='*') numTrees[i+1][j+1]=1;
			numTrees[i+1][j+1]+=numTrees[i+1][j]+numTrees[i][j+1]-numTrees[i][j];
		}
	}
	for(int i=0;i<q;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int x3=min(x1,x2), y3=min(y1,y2);
		int x4=max(x1,x2), y4=max(y1,y2);
		cout<<numTrees[x4][y4]-numTrees[x4][y3-1]-numTrees[x3-1][y4]+numTrees[x3-1][y3-1]<<'\n';		
	}
	return 0;
}