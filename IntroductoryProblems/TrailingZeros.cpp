//problem link: https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=5; i<=n; i*=5) cnt+=n/i;
	cout<<cnt;
	return 0;
}