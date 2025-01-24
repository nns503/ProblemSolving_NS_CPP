#include <bits/stdc++.h>

using namespace std;

vector<string> board(10);
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0x3f3f3f3f;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= 10 || x >= 10);
}

bool validateLine(int y){
    for(int x=0; x<10; x++){
        if(board[y][x] == 'O') return false;
    }

    return true;
}

char getAt(int y, int x){
    if(board[y][x] == '#') return 'O';
    return '#';
}

void changeAt(int y, int x){
    board[y][x] = getAt(y, x);
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        board[ny][nx] = getAt(ny, nx);
    }
}

void solve(int y, int x, int cnt){
    if(y == 10){
        if(validateLine(9)){
            answer = min(answer, cnt);
        }        
        return ;
    }
    
    if(y == 0){
        solve(y + (x+1) / 10, (x+1) % 10, cnt);
        changeAt(y, x);
        solve(y + (x+1) / 10, (x+1) % 10, cnt+1);
        changeAt(y, x);
    }
    else{
        if(board[y-1][x] == 'O'){
            changeAt(y, x);
            solve(y + (x+1) / 10, (x+1) % 10, cnt+1);
            changeAt(y, x);
        }
        else if(board[y-1][x] == '#'){
            solve(y + (x+1) / 10, (x+1) % 10, cnt);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(auto &cur : board){
        cin >> cur;
    }

    solve(0, 0, 0);

    if(answer == 0x3f3f3f3f) cout << -1;
    else cout << answer;

    return 0;
}