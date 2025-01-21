#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dy[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int r, c;
pair<int, int> jongsu;

int getLen(int y, int x){
    return abs(y - jongsu.Y) + abs(x - jongsu.X);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    vector<string> board(r);
    for(int y=0; y<r; y++) cin >> board[y];
    string str;
    cin >> str;

    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(board[y][x] == 'I'){
                jongsu = {y, x};
            }
        }
    }

    for(int i=0; i<str.size(); i++){
        int move = str[i] - '0';
        if(board[jongsu.Y + dy[move]][jongsu.X + dx[move]] == 'R'){
            cout << "kraj " << i+1 << '\n';
            return 0;
        }
        else{
            board[jongsu.Y][jongsu.X] = '.';
            jongsu = {jongsu.Y + dy[move], jongsu.X + dx[move]};
            board[jongsu.Y][jongsu.X] = 'I';
        }
        queue<pair<int, int>> q;
        map<pair<int, int>, int> m;
        vector<string> tempBoard(r);
        for(int y=0; y<r; y++){
            tempBoard[y] = board[y];
        }
        

        for(int y=0; y<r; y++){
            for(int x=0; x<c; x++){
                if(board[y][x] == 'R'){
                    int temp = 0x3f3f3f3f;
                    int my = y;
                    int mx = x;
                    for(int d=1; d<=9; d++){
                        if(d == 5) continue;
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(temp > getLen(ny, nx)){
                            temp = getLen(ny, nx);
                            my = ny;
                            mx = nx;
                        }
                    }
                    if(tempBoard[my][mx] == 'I'){
                        cout << "kraj " << i+1 << '\n';
                        return 0;
                    }
                    else{
                        tempBoard[my][mx] = 'R';
                        m[{my, mx}]++;
                    }
                }
            }
        }

        for(int y=0; y<r; y++){
            for(int x=0; x<c; x++){
                if(m[{y, x}] == 1){
                    board[y][x] = 'R';
                }
                else if(m[{y, x}] >= 2){
                    board[y][x] = '.';
                }
                else board[y][x] = '.';
            }
        }
        board[jongsu.Y][jongsu.X] = 'I';     
    }

    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            cout << board[y][x];
        }
        cout << '\n';
    }

    return 0;
}