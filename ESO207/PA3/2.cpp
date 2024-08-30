#include <bits/stdc++.h>

using namespace std;

int dfs(int ind,vector<int> v[], vector<int> &vis, vector<int>&ans, vector<int>&depth, vector<int>&parent)
{
    int h=depth[ind]+1;
    vis[ind]=1;
    for(auto it:v[ind]){
        if(vis[it]==0){
            depth[it]=depth[ind]+1;
            parent[it]=ind;
            h=min(h,dfs(it,v,vis,ans,depth,parent));
        }else if(parent[ind]!=it){
            h=min(h,depth[it]);
        }
    }
    if(h<=depth[ind]){
        ans[ind]=1;
    }
    return min(h,depth[ind]);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v[n];
    vector<int> vis(n,0),ans(n,0),depth(n,0),parent(n,0);
    int a[m],b[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        v[a[i]-1].push_back(b[i]-1);
        v[b[i]-1].push_back(a[i]-1);
    }
    for(int i=0;i<n;i++){
        if(vis[i]!=1){
            vis[i]=1;
            dfs(i,v,vis,ans,depth,parent);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
