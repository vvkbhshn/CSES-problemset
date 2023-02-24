//problem link: https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n;
	cin>>n;
	unordered_set<int> s;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		s.insert(num);
	}
	cout<<s.size();
	return 0;
}