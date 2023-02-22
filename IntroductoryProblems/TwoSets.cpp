//problem link: https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	ll n;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if(sum&1) cout<<"NO";
	else{
		bool arr[n+1]={false};
		ll cnt=0, num=n, rem=sum/2;
		while(rem>0){
			if(rem>=num){
				rem-=num;
				arr[num]=true;
				num--;
			}
			else{
				arr[rem]=true;
				rem=0;
			}
			cnt++;
		}
		cout<<"YES"<<'\n';
		cout<<cnt<<'\n';
		for(int i=1;i<=n;i++) if(arr[i]) cout<<i<<" ";
		cout<<'\n';
		cout<<n-cnt<<'\n';
		for(int i=1;i<=n;i++) if(!arr[i]) cout<<i<<" ";
	}
	return 0;
}