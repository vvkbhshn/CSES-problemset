#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n,m;
	cin>>n>>m;
	multiset<int> s;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	
	for(int i=0;i<m;i++){
		int maxPrice;
		cin>>maxPrice;
		auto it=s.upper_bound(maxPrice);
		if(it==s.begin()) cout<<-1<<'\n';
		else{
			cout<<*(--it)<<'\n';
			s.erase(it);
		}
	}
	return 0;
}