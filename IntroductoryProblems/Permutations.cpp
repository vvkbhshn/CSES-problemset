//problem link: https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(int n){
	if(n==1) cout<<1;
	else if(n<=3) cout<<"NO SOLUTION";
	else{
		for(int i=2;i<=n;i+=2) cout<<i<<" ";
		for(int i=1;i<=n;i+=2) cout<<i<<" ";
	}
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}