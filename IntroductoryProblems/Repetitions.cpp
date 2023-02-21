//problem link: https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	string s;
	cin>>s;
	int maxLen=0, currLen=0;
	char c=s[0];
	for(int i=0;i<s.length();i++){
		if(c==s[i]) currLen++;
		else{
			maxLen=max(maxLen,currLen);
			currLen=1;
			c=s[i];
		}
	}
	maxLen=max(maxLen,currLen);
	cout<<maxLen;
	return 0;
}