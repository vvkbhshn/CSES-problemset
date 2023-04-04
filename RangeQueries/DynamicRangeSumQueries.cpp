//problem link: https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void constructTree(ll tree[], int arr[], int ss, int se, int si){
	if(ss==se){
		tree[si]=arr[ss];
		return;
	}
	int mid=ss+(se-ss)/2;
	constructTree(tree,arr,ss,mid,2*si+1);
	constructTree(tree,arr,mid+1,se,2*si+2);
	tree[si]=tree[2*si+1]+tree[2*si+2];
}

ll getSum(ll tree[], int qs, int qe, int ss, int se, int si){
	if(qe<ss || qs>se) return 0;
	if(ss>=qs && se<=qe) return tree[si];
	int mid=(se+ss)/2;
	ll l=getSum(tree,qs,qe,ss,mid,2*si+1);
	ll r=getSum(tree,qs,qe,mid+1,se,2*si+2);
	return l+r;
}

void updateSum(ll tree[], int idx, int val, int ss, int se, int si){
	if(idx<ss || idx>se) return;
	if(ss==se && ss==idx) tree[si]=val;
	if(se>ss){
		int mid=(se+ss)/2;
		updateSum(tree,idx,val,ss,mid,2*si+1);
		updateSum(tree,idx,val,mid+1,se,2*si+2);
		tree[si]=tree[2*si+1]+tree[2*si+2];
	}	
}

int main(){
	int n, q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll tree[4*n];
	constructTree(tree,arr,0,n-1,0);
	for(int i=0;i<q;i++){
		ll query,x,y;
		cin>>query>>x>>y;
		if(query==1){
			arr[x-1]=y;
			updateSum(tree,x-1,y,0,n-1,0);
		}
		else cout<<getSum(tree,x-1,y-1,0,n-1,0)<<'\n';		
	}
	return 0;
}