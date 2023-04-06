//problem link: https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
using namespace std;

void constructTree(int tree[], int arr[], int ss, int se, int si){
	if(ss==se){
		tree[si]=arr[ss];
		return;
	}
	int mid=ss+(se-ss)/2;
	constructTree(tree,arr,ss,mid,2*si+1);
	constructTree(tree,arr,mid+1,se,2*si+2);
	tree[si]=min(tree[2*si+1],tree[2*si+2]);
}

int getMin(int tree[], int qs, int qe, int ss, int se, int si){
	if(qs>se || qe<ss) return INT_MAX;
	if(ss>=qs && se<=qe) return tree[si];
	int mid=ss+(se-ss)/2;
	int l=getMin(tree,qs,qe,ss,mid,2*si+1);
	int r=getMin(tree,qs,qe,mid+1,se,2*si+2);
	return min(l,r);
}

void updateMin(int tree[], int idx, int val, int ss, int se, int si){
	if(idx<ss || idx>se) return;
	if(ss==se && ss==idx) tree[si]=val;
	if(se>ss){
		int mid=ss+(se-ss)/2;
		updateMin(tree,idx,val,ss,mid,2*si+1);
		updateMin(tree,idx,val,mid+1,se,2*si+2);
		tree[si]=min(tree[2*si+1],tree[2*si+2]);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int arr[n], tree[4*n];
	for(int i=0;i<n;i++) cin>>arr[i];
	constructTree(tree,arr,0,n-1,0);	
	for(int i=0;i<m;i++){
		int q,x,y;
		cin>>q>>x>>y;
		if(q==1){
			arr[x-1]=y;
			updateMin(tree,x-1,y,0,n-1,0);
		}
		else{
			cout<<getMin(tree,x-1,y-1,0,n-1,0)<<'\n';
		}
	}
	return 0;
}