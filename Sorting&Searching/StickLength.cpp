//problem link: https://cses.fi/problemset/task/1074/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

ll findCost(int x, int arr[], int n){
	ll res=0;
	for(int i=0;i<n;i++) res+=abs(x-arr[i]);
	return res;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	int lo=INT_MAX, hi=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		lo=min(lo,arr[i]);
		hi=max(hi,arr[i]);
	}
	ll minCost=LLONG_MAX;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		ll cnt1=findCost(mid,arr,n);
		ll cnt2=findCost(mid+1,arr,n);
		if(cnt1<=cnt2){
			minCost=min(minCost,cnt1);
			hi=mid-1;
		}	
		else{
			minCost=min(minCost,cnt2);
			lo=mid+1;
		}
	}
	cout<<minCost;
	return 0;
}