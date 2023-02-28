//problem link: https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod =1e9+7;
 
ll binpow(ll a, ll b){
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
	while(n--){
		int a,b;
		cin>>a>>b;
		cout<<binpow(a,b)<<'\n';
	}
	return 0;
}