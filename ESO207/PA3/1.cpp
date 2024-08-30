#include <bits/stdc++.h>
using namespace std;
bool BFS(vector <int> adj[],vector <int> &ans,int k){
    queue <int> q;
    q.push(k);
    ans[k]=1;
    while(!q.empty()){
        int l=q.size();
        for(int i=0;i<l;i++){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(ans[it]==-1){
                    ans[it]=1+!(ans[node]-1);
                    q.push(it);
                }else if(ans[it]==ans[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector <int> adj[n];
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    vector <int> ans(n,-1);
    bool mark=true;
    for(int i=0;i<n;i++){
        if(ans[i]==-1 && BFS(adj,ans,i)==false) {
            mark=false;
            break;
        }
    }
    if(mark==true) {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"NO"<<endl;
    }

}