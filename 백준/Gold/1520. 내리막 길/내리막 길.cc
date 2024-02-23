#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int board[501][501];
int dist[501][501];
priority_queue<tuple<int, int, int>> pq;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= m || x >= n);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    dist[0][0] = 1;
    pq.push(make_tuple(board[0][0], 0, 0));

    while(!pq.empty()){
        int num, y, x;
        tie(num, y, x) = pq.top(); pq.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[y][x] <= board[ny][nx]) continue;
            if(dist[ny][nx] == 0) pq.push(make_tuple(board[ny][nx], ny, nx));
            dist[ny][nx] += dist[y][x];
        }
    }

    cout << dist[m-1][n-1];
    return 0;
}