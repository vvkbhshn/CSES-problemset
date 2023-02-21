//problem link: https://cses.fi/problemset/task/1071/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		ll d=max(x,y);
		ll res=0;
		if(d%2==0) swap(x,y);
		if(x>=y) res=(d-1)*(d-1)+y;
		else res=d*d-(x-1);
		cout<<res<<'\n';
	}
	return 0;
}