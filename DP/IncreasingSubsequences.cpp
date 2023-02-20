//problem link: https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int findCeil(int num, vector<int> &v){
	int lo=0, hi=v.size()-1;
	int idx=hi;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(v[mid]>=num){
			idx=mid;
			hi=mid-1;
		}
		else lo=mid+1;
	}
	return idx;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<int> v;
	v.push_back(arr[0]);
	for(int i=1;i<n;i++){
		if(arr[i]>v.back()) v.push_back(arr[i]);
		else{
			int idx=findCeil(arr[i],v);
			v[idx]=arr[i];
		}
	}
	cout<<v.size();
	return 0;
}