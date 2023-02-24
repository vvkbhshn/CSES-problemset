//problem link: https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	int n,x;
	cin>>n>>x;
	int w[n];
	for(int i=0;i<n;i++) cin>>w[i];
	sort(w,w+n);
	int i=0, j=n-1;
	int cnt=0;
	while(i<j){
		if(w[j]>x) j--;
		else if(w[i]+w[j]>x){
			cnt++;
			j--;
		}		
		else{
			cnt++;
			i++;
			j--;
		}
	}
	if(i==j && w[i]<x) cnt++;
	cout<<cnt;
	return 0;
}