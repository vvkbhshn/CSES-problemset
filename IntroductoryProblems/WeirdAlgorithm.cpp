//problem link: https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	ll n;
	cin>>n;
	while(true){
		cout<<n<<" ";
		if(n==1) break;
		if(n&1) n=3*n+1;
		else n/=2;
	}
	return 0;
}