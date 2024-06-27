#include <bits/stdc++.h>
#define L first
#define N second

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void getLen(int st, vector<int> &len, vector<vector<pair<int, int>>> &adj){

    len[st] = 0;
    pq.push({len[st], st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(len[cur.N] != cur.L) continue;
        for(auto nxt : adj[cur.N]){
            if(len[nxt.N] > len[cur.N] + nxt.L){
                len[nxt.N] = len[cur.N] + nxt.L;
                pq.push({len[nxt.N], nxt.N});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    if(a == b){
        cout << 0;
        return 0;
    }
    vector<vector<pair<int, int>>> adj(n+1);     

    for(int i=0; i<n-1; i++){
        int q, w, e;
        cin >> q >> w >> e;
        adj[q].push_back({e, w});
        adj[w].push_back({e, q});
    }

    vector<int> aLen(n+1, 0x3f3f3f3f);
    vector<int> bLen(n+1, 0x3f3f3f3f);

    getLen(a, aLen, adj);
    getLen(b, bLen, adj);

    int ans = 0x3f3f3f3f;

    for(int i=1; i<=n; i++){
        for(auto nxt : adj[i]){
            ans = min(ans, aLen[i] + bLen[nxt.N]);
        }
    }

    cout << ans;
    return 0;
}
