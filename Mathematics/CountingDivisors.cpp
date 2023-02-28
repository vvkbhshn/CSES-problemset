//problem link: https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod =1e9+7;
const int N=1e6+1;
 
int divisors[N];
void solve(){
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j+=i){
			divisors[j]++;
		}
	}
}
 
int main(){
	memset(divisors,0,sizeof divisors);
	solve();
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		cout<<divisors[x]<<'\n';
	}
	return 0;
}