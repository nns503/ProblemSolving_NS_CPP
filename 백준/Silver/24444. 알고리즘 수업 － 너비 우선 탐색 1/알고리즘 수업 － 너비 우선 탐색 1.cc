#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> arr[n+1];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    vector<int> vis(n+1, 0);
    queue<int> q;
    q.push(r);

    int index = 2;
    vis[r] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        vector<int> num;
        for(auto nxt : arr[cur]){
            if(vis[nxt] != 0) continue;
            num.push_back(nxt);
        }
        sort(num.begin(), num.end());
        for(auto number : num){
            vis[number] = index++;
            q.push(number);
        }
    } 

    for(int i=1; i<=n; i++) cout << vis[i] << '\n';
    return 0;
}