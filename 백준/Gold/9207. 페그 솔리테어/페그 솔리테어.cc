#include <bits/stdc++.h>

using namespace std;


int ansCount;
int ansK;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= 5 || x >= 9);
}

void solve(vector<string> &board, int count, int k){
    if(k == ansK){
        ansCount = min(ansCount, count);
    }
    if(k < ansK){
        ansK = k;
        ansCount = count;
    }

    for(int y=0; y<5; y++){
        for(int x=0; x<board[y].size(); x++){
            auto cur = board[y][x];
            if(cur != 'o') continue;
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(OOB(ny, nx)) continue;
                if(board[ny][nx] != 'o') continue;
                if(OOB(ny + dy[i], nx + dx[i])) continue;
                if(board[ny + dy[i]][nx + dx[i]] != '.') continue;
                vector<string> temp = (board);
                temp[y][x] = '.';
                temp[ny][nx] = '.';
                temp[ny + dy[i]][nx + dx[i]] = 'o';
                solve(temp, count+1, k-1);
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        vector<string> board(5);
        ansK = 0;
        ansCount = 0x3f3f3f3f;
        for(auto &line : board){
            cin >> line;
        }
        for(int y=0; y<5; y++){
            for(int x=0; x<board[y].size(); x++){
                if(board[y][x] == 'o') ansK++;
            }
        }
        solve(board, 0, ansK);
        cout << ansK << ' ' << ansCount << '\n';
    }
    return 0;
}