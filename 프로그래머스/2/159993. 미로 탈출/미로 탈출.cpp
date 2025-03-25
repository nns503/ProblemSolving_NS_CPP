#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int maxY, maxX;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= maxY || x >= maxX);
}

int solve(int stY, int stX, vector<string> &board, char target){
    queue<pair<int, int>> q;
    q.push({stY, stX});
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), -1));
    vis[stY][stX] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(board[cur.Y][cur.X] == target){
            return vis[cur.Y][cur.X];
        }
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx] != -1) continue;
            if(board[ny][nx] == 'X') continue;
            q.push({ny, nx});
            vis[ny][nx] = vis[cur.Y][cur.X] + 1;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    maxY = maps.size();
    maxX = maps[0].size();
    vector<pair<int, int>> p(2);
    
    for(int y=0; y<maxY; y++){
        for(int x=0; x<maxX; x++){
            if(maps[y][x] == 'S'){
                p[0] = {y, x};
            }
            if(maps[y][x] == 'L'){
                p[1] = {y, x};
            }
        }
    }
    
    int temp1 = solve(p[0].Y, p[0].X, maps, 'L');
    if(temp1 == -1) return -1;
    int temp2 = solve(p[1].Y, p[1].X, maps, 'E');
    if(temp2 == -1) return -1;
    return temp1 + temp2;
}