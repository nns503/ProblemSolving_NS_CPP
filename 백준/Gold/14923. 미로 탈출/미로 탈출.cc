#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int board[1001][1001];
int dist[1001][1001][2];
int n, m;
int hy, hx, ex, ey;
queue<tuple<int, int, int>> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y <= 0 || x <= 0 || y > n || x > m);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> hy >> hx >> ey >> ex;

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            cin >> board[y][x];
        }
    }

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            dist[y][x][0] = INF;
            dist[y][x][1] = INF;
        }
    }

    q.push(make_tuple(hy, hx, 0));
    dist[hy][hx][0] = 0;

    while(!q.empty()){
        int y, x, a;
        tie(y, x, a) = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == 1){
                if(a == 0 && dist[ny][nx][1] > dist[y][x][0] + 1){
                    dist[ny][nx][1] = dist[y][x][0] + 1;
                    q.push(make_tuple(ny, nx, 1));
                }
                else if(a == 1) continue;
                
            }
            else if(board[ny][nx] == 0 && dist[ny][nx][a] > dist[y][x][a] + 1){
                dist[ny][nx][a] = dist[y][x][a] + 1;
                q.push(make_tuple(ny, nx, a));
            }
        }
    }

    int answer = min(dist[ey][ex][0], dist[ey][ex][1]);
    cout << (answer == INF ? -1 : answer);
    
    return 0;   
}