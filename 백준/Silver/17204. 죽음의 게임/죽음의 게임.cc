#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &cur: arr) cin >> cur;
    vector<int> dist(n, -1);

    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int nxt = arr[cur];
        if(dist[nxt] != -1) continue;
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
    }

    cout << dist[k];
    return 0;
}