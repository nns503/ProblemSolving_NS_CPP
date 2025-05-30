#include <bits/stdc++.h>

using namespace std;

void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis){
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, adj, vis);
    }
}

int solve(int n, vector<int> &arr){
    int count = 0;
    vector<vector<int>> adj(n+1);

    for(int i=0; i<n; i++){
        adj[i+1].push_back(arr[i]);
    }

    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        count++;
        dfs(i, adj, vis);
    }

    return count;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &cur : arr){
            cin >> cur;
        }
        cout << solve(n, arr) << '\n'; 
    }
    return 0;
}