#include <bits/stdc++.h>

using namespace std;

int n;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= n);
}
int getLen(vector<string> &board){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    pq.push({0, 0, 0});
    vis[0][0] = true;

    while(!pq.empty()){
        int l, y, x;
        tie(l, y, x) = pq.top(); pq.pop();
        if(y == n-1 && x == n-1) return l;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            if(board[ny][nx] == '0') pq.push({l+1, ny, nx});
            else pq.push({l, ny, nx});
        }
    }

    return -1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> board(n);
    for(int i=0; i<n; i++){
        cin >> board[i];
    }

    cout << getLen(board);

    return 0;
}