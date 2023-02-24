//problem link: https://cses.fi/problemset/task/1629/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

bool comp(pair<int,int> &a, pair<int,int> &b){
	return a.second<b.second;
}

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end(),comp);
	int cnt=1, prev=v[0].second;
	for(int i=1;i<n;i++){
		if(v[i].first>=prev){
			cnt++;
			prev=v[i].second;
		}
	}
	cout<<cnt;
	return 0;
}