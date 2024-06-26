#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool OOB(int y, int x, int n){
    return (y >= n || x >= n || y < 0 || x < 0);
}

void setBoard(vector<vector<int>> &board, int n){
    int y = 0;
    int x = 0;
    int number = n*n;
    int len = n;
    int dir = 0;
    while(number){
        board[y][x] = number--;
        y += dy[dir];
        x += dx[dir];
        if(OOB(y, x, n) || board[y][x] != -1){
            y -= dy[dir];
            x -= dx[dir];
            dir = (dir + 1) % 4;
            y += dy[dir];
            x += dx[dir];
        }
    }    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    int ansY, ansX;
    cin >> n >> target;

    vector<vector<int>> board(n, vector<int>(n, -1));
    setBoard(board, n);
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cout << board[y][x] << ' ';
            if(board[y][x] == target){
                ansY = y;
                ansX = x;
            }
        }
        cout << '\n';
    }
    cout << ansY+1 << ' ' << ansX+1;
    return 0;
}
