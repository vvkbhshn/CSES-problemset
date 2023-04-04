//problem link: https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,q;
	cin>>n>>q;
	int arr[n];
	vector<ll> prefSum;
	prefSum.push_back(0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		prefSum.push_back(arr[i]+prefSum.back());
	}
	for(int i=0;i<q;i++){
		int qs,qe;
		cin>>qs>>qe;
		cout<<prefSum[qe]-prefSum[qs-1]<<'\n';
	}
	return 0;
}