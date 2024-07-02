#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(20, vector<int>(20));
int dy[4] = {1, 0, 1, -1};
int dx[4] = {0, 1, 1, 1};
bool vis[20][20][4];
bool OOB(int y, int x){
    return (y < 1 || x < 1 || y > 19 || x > 19);
}

bool checkWin(int y, int x){
    int cur = board[y][x];
    for(int i=0; i<4; i++){
        if(vis[y][x][i]) continue;
        int ny = y;
        int nx = x;
        int len = 0;
        while(!OOB(ny, nx)){
            if(cur != board[ny][nx]) break;
            vis[ny][nx][i] = true;
            ny += dy[i];
            nx += dx[i];
            len++;
        }

        if(len == 5) return true;
    }
    return false;   
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int y=1; y<=19; y++){
        for(int x=1; x<=19; x++){
            cin >> board[y][x];
        }
    }

    for(int x=1; x<=19; x++){
        for(int y=1; y<=19; y++){
            if(board[y][x] == 0) continue;
            if(checkWin(y, x)){
                cout << board[y][x] << '\n';
                cout << y << ' ' << x;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}