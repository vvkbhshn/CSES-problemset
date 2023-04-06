//problem link: https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	int arr[n], prefXor[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int x=0;
	for(int i=0;i<n;i++){
		x^=arr[i];
		prefXor[i]=x;
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		if(a==0) cout<<prefXor[b]<<'\n';
		else cout<<(prefXor[b]^prefXor[a-1])<<'\n';
	}
	return 0;
}
	