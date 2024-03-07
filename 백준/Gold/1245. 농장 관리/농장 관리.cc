#include <bits/stdc++.h>
#define Y first 
#define X second

using namespace std;

int board[101][101];
bool vis[101][101];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, answer;
bool chk = true;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

void func(int y, int x){
    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        if(board[ny][nx] > board[y][x]){
            chk = false;
        }
        else if(!vis[ny][nx] && board[ny][nx] == board[y][x]){
            vis[ny][nx] = true;
            func(ny, nx);
        }
        
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin >> board[y][x];
        }
    }

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(vis[y][x]) continue;
            vis[y][x] = true;
            func(y, x);
            if(chk){
                answer++;
            }
            else chk = true;;
        }
    }

    cout << answer;

    return 0;
}