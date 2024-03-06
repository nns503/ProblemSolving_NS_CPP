#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
string board[1001];
bool vis[1001][1001];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char curDir[4] = {'U', 'D', 'L', 'R'};
char dir[4] = {'D', 'U', 'R', 'L'};
int answer;
queue<pair<int, int>> q;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

void BFS(){
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            if(curDir[i] != board[cur.Y][cur.X]) continue;
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx}); 
        }

        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[ny][nx] != dir[i]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int y=0; y<n; y++) cin >> board[y];

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(vis[y][x]) continue;
            answer++;
            vis[y][x] = true;
            q.push({y, x});
            BFS();
        }
    }


    cout << answer;
    return 0;
}