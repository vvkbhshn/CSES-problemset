//problem link: https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll res=0;
	for(int i=1;i<n;i++){
		if(arr[i]<arr[i-1]){
			res+=arr[i-1]-arr[i];
			arr[i]=arr[i-1];
		}
	}
	cout<<res;
	return 0;
}