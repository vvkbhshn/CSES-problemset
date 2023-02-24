//problem link: https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

// KADANE'S ALGORITHM

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll maxSum=arr[0], currSum=0;
	for(int i=0;i<n;i++){
		currSum+=arr[i];
		maxSum=max(maxSum,currSum);
		if(currSum<0) currSum=0;
	}
	cout<<maxSum;
	return 0;
}