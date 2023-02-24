//problem link: https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int x,n;
	cin>>x>>n;
	set<int> pos;
	multiset<int> len;
	pos.insert(0);
	pos.insert(x);
	len.insert(x);
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		auto it=pos.upper_bound(num);
		int right=*(it);
		int left=*(--it);
		int diff=right-left;
		pos.insert(num);
		it=len.find(diff);
		len.erase(it);
		len.insert(num-left);
		len.insert(right-num);
		it=len.end();
		cout<<*(--it)<<" ";
	}	
	return 0;
}