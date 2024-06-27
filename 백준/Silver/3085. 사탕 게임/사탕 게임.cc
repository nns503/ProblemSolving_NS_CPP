#include <bits/stdc++.h>

using namespace std;

int n;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OOB(int y, int x){
    return (y >= n || x >= n || x < 0 || y < 0);
}

int getLen(vector<string> &board, int y, int x){
    int len = 0;
    int temp = 1;
    for(int i=1; i<n; i++){
        if(board[y][i] == board[y][i-1]) temp++;
        else{
            len = max(len, temp);
            temp = 1;
        }
    }
    len = max(len, temp);
    temp = 1;
    for(int i=1; i<n; i++){
        if(board[i][x] == board[i-1][x]) temp++;
        else{
            len = max(len, temp);
            temp = 1;
        }
    }
    len = max(len, temp);

    return len;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<string> board(n);

    for(int i=0; i<n; i++) cin >> board[i];
;
    int ans = 0;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            ans = max(ans, getLen(board, y, x));
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(OOB(ny, nx)) continue;
                if(board[ny][nx] == board[y][x]) continue;
                swap(board[ny][nx], board[y][x]);
                ans = max(ans, getLen(board, y, x));
                swap(board[ny][nx], board[y][x]);
            }
        }
    }

    cout << ans;
    return 0;
}