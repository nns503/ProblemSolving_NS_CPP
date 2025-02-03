#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= r || x >= c);
}

void solve(int n, vector<string> &board, int y, int x){
    if(n == k){
        if(y == 0 && x == c-1) answer++;
        return ;
    }

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        if(board[ny][nx] != '.') continue;
        board[ny][nx] = '!';
        solve(n+1, board, ny, nx);
        board[ny][nx] = '.';
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    vector<string> board(r);

    for(auto &str : board) cin >> str;
    board[r-1][0] = '!';
    solve(1, board, r-1, 0);
    cout << answer;
}