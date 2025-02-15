#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;
    vector<int> target(arr);
    sort(target.begin(), target.end());
    map<vector<int>, int> dist;
    dist[arr] = 0;

    queue<vector<int>> q; 
    q.push(arr);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<=n-k; i++){
            vector<int> temp(cur);
            reverse(temp.begin() + i, temp.begin() + i + k);
            if(dist.find(temp) != dist.end()) continue;
            dist[temp] = dist[cur] + 1;
            q.push(temp);
        }
    }

    if(dist.find(target) == dist.end()) cout << -1;
    else cout << dist[target];

    return 0;
}