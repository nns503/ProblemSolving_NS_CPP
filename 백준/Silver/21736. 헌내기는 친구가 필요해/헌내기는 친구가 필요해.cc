#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

string board[601];
bool vis[601][601];
int n, m, answer;
queue<pair<int, int>> q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int y=0; y<n; y++) cin >> board[y];

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x] == 'I'){
                q.push({y, x});
                vis[y][x] = true;
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[ny][nx] == 'X') continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
            if(board[ny][nx] == 'P') answer++;
        }
    }

    if(answer == 0) cout << "TT";
    else cout << answer;

    return 0;
}