#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, k;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int score[21][21];

bool OOB(int y, int x){
    return (y < 1 || x < 1 || y > n || x > m);
}

int getScore(int y, int x, vector<vector<int>> &board){
    queue<pair<int, int>> q;    
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
    q.push({y, x});
    vis[y][x] = true;
    int cnt = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[y][x] != board[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
        }
    }
    return score[y][x] = cnt * board[y][x];
}

int solve(vector<vector<int>> &board){
    int y = 1, x = 1;
    int d = 0; 
    int sum = 0;
    vector<int> dice = {0, 1, 2, 3, 4, 5, 6};
    while(k--){
        y += dy[d];
        x += dx[d];
        if(OOB(y, x)){
            d = (d + 2) % 4;
            y += (dy[d] * 2);
            x += (dx[d] * 2);
        }
        sum += score[y][x];

        int temp = dice[1];
        if(d == 0){
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }
        else if(d == 1){
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        else if(d == 2){
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }
        else if(d == 3){
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }

        if(dice[6] > board[y][x]) d = (d + 1) % 4;
        else if(dice[6] < board[y][x]) d = (d + 3) % 4;
    }
    return sum;

}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    vector<vector<int>> board(n+1, vector<int>(m+1, 0));

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            cin >> board[y][x];
        }
    }

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            getScore(y, x, board);
        }
    }

    cout << solve(board);
    return 0;
}