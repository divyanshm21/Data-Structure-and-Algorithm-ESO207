#include <bits/stdc++.h>

using namespace std;

int modified_dfs(vector<int> adj[], int node,vector <int> &A, vector <int>&B,vector <int>&vis, vector <int>& dp, vector <int>& n_lca) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (vis[it]==0)
            dp[node] += modified_dfs(adj, it,A,B,vis,dp,n_lca) - n_lca[it];
    }
    return dp[node];
}

int least_common_ancestor(vector<vector<int>> &dpmat, int u, int v,vector <int> &A, vector <int>&B,int l) {
    if (A[u] <= A[v] && B[u] >= B[v]) return u;
    else if (A[v] <= A[u] && B[v] >= B[u]) return v;
    int i=l;
    while(i>=0) {
        if (A[dpmat[u][i]] > A[v] || B[dpmat[u][i]] < B[v]) u = dpmat[u][i];
        i--;
    }
    return dpmat[u][0];

}

void dfs(vector<vector<int>> &dpmat, vector<int> adj[], int node, int parent,vector <int> &A, vector <int>&B,int l,int &val) {
    A[node] = ++val;
    dpmat[node][0] = parent;

    for (int i = 1; i <= l; ++i){
        dpmat[node][i] = dpmat[dpmat[node][i - 1]][i - 1];
    }

    for (auto it : adj[node]) {
        if (it != parent) dfs(dpmat, adj, it, node,A,B,l,val);
    }

    B[node] = ++val;
}

bool check(int t, int x){
    int n=1;
    while(t--){
        n*=2;
    }
    if(n==x) return true;
    else return false;
}

int fulog(int n){
    int t=0;
    int x=n;
    while(n!=1){
        n/=2;
        t++;
    }
    if(check(t,x)==true) return t;
    else return t+1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> A(n+1),B(n+1);
    int P[n-1],Q[n-1];
    for (int i = 0; i < n - 1; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> Q[i];
    }
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
        adj[P[i]].push_back(Q[i]);
        adj[Q[i]].push_back(P[i]);
    }
    vector<int> dp(n+1,0), n_lca(n+1,0), vis(n+1,0);
    int l = fulog(n);
    vector<vector<int>> dpmat(n + 1, vector<int>(l + 1, 0));
    int val=0;
    dfs(dpmat, adj, 1, 1,A,B,l,val);
    int x;
    while(k--) {
        int a, b;
        cin >> a >> b;
        dp[b]++;
        dp[a]++;
        x = least_common_ancestor(dpmat, a, b,A,B,l);
        dp[x]--;
        n_lca[x]++;
    }
    modified_dfs(adj, 1,A,B,vis,dp, n_lca);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}