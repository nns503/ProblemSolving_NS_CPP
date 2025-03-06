#include <bits/stdc++.h>

using namespace std;

int h, w;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int dist[26][26][2];

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= h || x >= w);
}

void solve(int stY, int stX, int startD, vector<vector<int>> &board){
    queue<tuple<int, int, int, int>> q;
    q.push({stY, stX, startD, 0});
    while(!q.empty()){
        int y, x, d, len;
        tie(y, x, d, len) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == 1) continue; 
            bool corner = (d % 2 != i % 2);
            if(corner){
                if(dist[ny][nx][corner] <= len + 600) continue;
                dist[ny][nx][corner] = len + 600;
            }
            else{
                if(dist[ny][nx][corner] <= len + 100) continue;
                dist[ny][nx][corner] = len + 100;
            }
            q.push({ny, nx, i, dist[ny][nx][corner]});
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    h = board.size();
    w = board[0].size();
    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            for(int d=0; d<2; d++){
                dist[y][x][d] = 0x3f3f3f3f;
            }
        }
    }
    
    dist[0][0][0] = 0;
    dist[0][0][1] = 0;
    
    if(board[0][1] != 1){
        solve(0, 0, 1, board);
    }
    answer = min(dist[h-1][w-1][1], dist[h-1][w-1][0]);
    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            for(int d=0; d<2; d++){
                dist[y][x][d] = 0x3f3f3f3f;
            }
        }
    }
    if(board[1][0] != 1){
        solve(0, 0, 0, board);
    }
    int temp = min(dist[h-1][w-1][1], dist[h-1][w-1][0]);
    answer = min(answer, temp);
    
    return answer;
}