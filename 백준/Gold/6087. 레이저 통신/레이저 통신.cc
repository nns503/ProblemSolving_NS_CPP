#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int w, h;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<vector<int>>> dist(101, vector<vector<int>>(101, vector<int>(4, 0x3f3f3f3f)));

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= h || x >= w);
}

int BFS(int stY, int stX, int targetY, int targetX, vector<string> &board){
    queue<tuple<int, int, int>> q;

    for(int i=0; i<4; i++){
        dist[stY][stX][i] = 0;
        q.push({stY, stX, i});
    }

    int answer = 0x3f3f3f3f;
    while(!q.empty()){
        int y, x, d;
        tie(y, x, d) = q.front(); q.pop();
        if(y == targetY && x == targetX){
            answer = min(dist[y][x][d], answer);
            continue;
        }
        for(int i=-1; i<=1; i++){
            int nd = (d + i + 4) % 4;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == '*') continue;
            if(dist[ny][nx][nd] <= dist[y][x][d] + abs(i)) continue;
            dist[ny][nx][nd] = dist[y][x][d] + abs(i);
            q.push({ny, nx, nd});
        }
    }
    return answer;;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    vector<string> board(h);

    for(int y=0; y<h; y++){
        cin >> board[y];
    }
    bool flag = false;
    int startY, startX;
    int targetY, targetX;
    for(int y=0; y<h; y++){
        
        for(int x=0; x<w; x++){
            if(board[y][x] == 'C'){
                if(!flag){
                    startY = y;
                    startX = x;
                    flag = true;
                }
                else{
                    targetY = y;
                    targetX = x;
                }
                
            }
        }
    }

    cout << BFS(startY, startX, targetY, targetX, board);

    
    return 0;
}