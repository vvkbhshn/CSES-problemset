//problem link: https://cses.fi/problemset/task/1141/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	unordered_map<int,int> mp;
	int res=0;
	int i=0, j=0;
	while(j<n){
		if(mp.find(arr[j])!=mp.end()){
			i=max(i,mp[arr[j]]+1);			
		}
		res=max(res,j-i+1);
		mp[arr[j]]=j;
		j++;
	}
	cout<<res;
	return 0;
}