#include <bits/stdc++.h>

using namespace std;

int solve(int n, int a, int b, int m, vector<vector<int>> &arr){
    vector<int> adj[n+1];
    for(int i=0; i<arr.size(); i++){
        int x = arr[i][0];
        int y = arr[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n+1, -1);
    dist[a] = 0;
    queue<int> q;
    q.push(a);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    return dist[b];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    vector<vector<int>> arr(m, vector<int>(2));
    for(int i=0; i<m; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    cout << solve(n, a, b, m, arr);

    return 0;
}