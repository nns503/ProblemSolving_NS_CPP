#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n;
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};

bool OOB(int y, int x){
    return (y < 0 | x < 0 | y >= n | x >= n);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, -1));
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    queue<pair<int, int>> q;

    q.push({r1, c1});
    board[r1][c1] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<6; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] != -1) continue;
            board[ny][nx] = board[cur.Y][cur.X] + 1;
            q.push({ny, nx});
        }
    }
    
    cout << board[r2][c2];
    
    return 0;
}