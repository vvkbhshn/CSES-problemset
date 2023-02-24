//problem link: https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	int size=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(mp.find(num-1)!=mp.end()){
			mp[num]=mp[num-1];
		}
		else{
			size++;
			mp[num]=size;
		}
	}
	cout<<size;
	return 0;
}