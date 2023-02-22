//problem link: https://cses.fi/problemset/task/1754/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		if(b>2*a){
			cout<<"NO\n";
			continue;
		}
		int d=b-a;
		a-=d;
		b-=2*d;
		// now a and b become equal
		if(a%3==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}