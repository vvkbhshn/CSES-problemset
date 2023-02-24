//problem link: https://cses.fi/problemset/task/1619/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int findCount(int num, vector<int> &v){
	int lo=0, hi=v.size()-1;
	int idx=v.size();
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(v[mid]>num) lo=mid+1;
		else{
			idx=mid;
			hi=mid-1;
		}
	}
	return v.size()-idx;
}

int main(){
	int n;
	cin>>n;
	vector<int> entry(n), exit(n);
	for(int i=0;i<n;i++){
		cin>>entry[i]>>exit[i];
	}
	sort(entry.rbegin(),entry.rend());
	sort(exit.begin(),exit.end());
	int res=0;
	for(int i=0;i<n;i++){
		int cnt=findCount(exit[i], entry);
		if(i==0 || exit[i]-exit[i-1]>1)	res=max(res, cnt);
		else res=max(res, cnt-1);			
		entry.pop_back();
	}
	cout<<res;
	return 0;
}