#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n;

bool OOB(int y, int x){
    return (y >= m || x >= n || y < 0 || x < 0);
}

void BFS(int y, int x, vector<vector<int>> &board, vector<vector<bool>> &vis){
    queue<pair<int, int>> q;
    vis[y][x] = true;
    q.push({y, x});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[ny][nx] != 1) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n, 0));
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    int answer = 0;
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(board[y][x] != 1) continue;
            if(vis[y][x]) continue;
            answer++;
            BFS(y, x, board, vis);
        }
    }

    cout << answer;

    return 0;
}