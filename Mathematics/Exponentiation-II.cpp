//problem link: https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod =1e9+7;
 
ll binpow(ll a, ll b, ll m){
	a%=m;
	ll res=1;
	while(b>0){
		if(b&1) res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}
 
int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		int x=binpow(b,c,mod-1);		
		int res=binpow(a,x,mod);		
		cout<<res<<'\n';
	}
	return 0;
}