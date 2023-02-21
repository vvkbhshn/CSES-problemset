//problem link: https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int arr[n-1];
	bool present[n+1]={false};
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
		present[arr[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!present[i]){
			cout<<i;
			break;
		}
	}
	return 0;
}