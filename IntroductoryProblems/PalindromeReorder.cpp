//problem link: https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

string solve(string &s){
	int n=s.length();
	int freq[26]={0};
	for(auto c:s) freq[c-'A']++;
	int odd=0;
	for(int i=0;i<26;i++) if(freq[i]&1) odd++;
	if(((n&1) && (odd>1)) || (n%2==0 && (odd>0))) return "NO SOLUTION";
	string res(n,'.');
	int index=0;
	for(int i=0;i<26;i++){
		char c='A'+i;
		if(freq[i]&1){
			res[n/2]=c;
			freq[i]--;
		}
		for(int j=0;j<freq[i]/2;j++){
			res[index]=c;
			res[n-1-index]=c;
			index++;
		}
	}
	return res;
}

int main(){
	string s;
	cin>>s;
	cout<<solve(s);	
	return 0;
}