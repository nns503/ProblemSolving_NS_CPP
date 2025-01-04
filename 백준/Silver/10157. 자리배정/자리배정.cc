#include <bits/stdc++.h>

using namespace std;

int c, r;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OOB(int y, int x){
    return (x < 0 || y < 0 || x >= c || y >= r);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> r;
    vector<vector<bool>> board(r, vector<bool>(c, false));

    int k;
    cin >> k;

    if(k > c*r){
        cout << 0;
        return 0;
    }

    k--;
    int d = 0;
    int curY = r-1;
    int curX = 0;
    board[curY][curX] = true;
    
    while(k--){
        int ny = curY + dy[d];
        int nx = curX + dx[d];
        if(OOB(ny, nx) || board[ny][nx] == true){
            d = (d+1) % 4;
        }
        curY = curY + dy[d];
        curX = curX + dx[d];
        board[curY][curX] = true;
    }
    
    cout << curX + 1<< ' ' << r - curY;
    return 0;
}