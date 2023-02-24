//problem link: https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]=i+1;
	}
	bool found=false;
	for(int i=0;i<n;i++){
		if(arr[i]*2==x && i+1==mp[arr[i]]) continue;
		if(mp.find(x-arr[i])!=mp.end()){			
			cout<<i+1<<" "<<mp[x-arr[i]];
			found=true;
			break;
		}
	}
	if(!found) cout<<"IMPOSSIBLE";
	return 0;
}