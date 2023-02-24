//problem link: https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n), b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<m;j++) cin>>b[j];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int cnt=0;
	while(!a.empty() && !b.empty()){
		if(abs(a.back()-b.back())<=k){
			cnt++;
			a.pop_back();
			b.pop_back();
		}
		else{
			if(a.back()>b.back()) a.pop_back();
			else b.pop_back();
		}
	}
	cout<<cnt;
	return 0;
}