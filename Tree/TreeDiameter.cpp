//problem link: https://cses.fi/problemset/task/1131/

#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
 
vector<int> adj[N];
 
int dfs(int u, int parent, int &diameter){
    int len1=0, len2=0;
    bool leaf=true;
    for(auto v:adj[u]){
        if(v!=parent){
            int depth=dfs(v,u,diameter);
            if(depth>len1){
                len2=len1;
                len1=depth;
            }
            else if(depth>len2){
                len2=depth;
            }
            leaf=false;
        }
    }   
    if(leaf) return 1;
    diameter=max(diameter, len1+len2);
    return len1+1;
}
 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diameter=0;
    dfs(1,0,diameter);
    cout<<diameter;
    return 0;
}