#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int r, c;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= r || x >= c);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    vector<string> board(r);

    for(int y=0; y<r; y++){
        cin >> board[y];
    }

    int t = 50;
    vector<string> temp(board);
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            int cnt = 0;
            if(board[y][x] == '.') continue;
            for(int i=0; i<4; i++){
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if(OOB(ny, nx) || board[ny][nx] == '.'){
                    cnt++;
                }
            }
            if(cnt >= 3) temp[y][x] = '.';
        }
    }

    int ax = 0x3f3f3f3f;
    int ay = 0x3f3f3f3f;
    int bx = -1;
    int by = -1;

    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(temp[y][x] == 'X'){
                ax = min(ax, x);
                bx = max(bx, x);
                ay = min(ay, y);
                by = max(by, y);
            }
        }
    }

    for(int y=ay; y<=by; y++){
        for(int x=ax; x<=bx; x++){
            cout << temp[y][x];
        }
        cout << '\n';
    }
}