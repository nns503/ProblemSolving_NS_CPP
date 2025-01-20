#include <bits/stdc++.h>

using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int answer = -1;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= 4 || x >= 4);
}

void solve(int cnt, int index, vector<vector<int>> &board, vector<tuple<int, int, int>> &fish){
    int y, x, d;
    if(index == 17){
        tie(y, x, d) = fish[0];
        int a = 0;
        while(true){
            a++;
            int ny = y + dy[d] * a;
            int nx = x + dx[d] * a;
            if(OOB(ny, nx)) break;
            if(board[ny][nx] == -1) continue;

            int number = board[ny][nx];
            auto temp = fish[number];
            fish[number] = {-1, -1, -1};
            fish[0] = temp;
            board[y][x] = -1;
            board[ny][nx] = 0;
            solve(cnt + number, 1, board, fish);
            fish[number] = temp;
            fish[0] = {y, x, d};
            board[y][x] = 0;
            board[ny][nx] = number;
            answer = max(answer, cnt + number);
        }
        return ;
    }

    tie(y, x, d) = fish[index];
    if(y == -1){
        solve(cnt, index+1, board, fish);
        return ;
    }

    for(int i=0; i<8; i++){
        int nd = (d + i) % 8;
        int ny = y + dy[nd];
        int nx = x + dx[nd];
        if(OOB(ny, nx)) continue;
        if(board[ny][nx] == 0) continue;
        if(board[ny][nx] != -1){
            int prv = board[y][x];
            int number = board[ny][nx];
            tuple<int, int, int> prvTemp = fish[prv];
            auto temp = fish[number];
            board[y][x] = number;
            board[ny][nx] = prv;
            fish[prv] = {ny, nx, nd};
            fish[number] = {y, x, get<2>(temp)};
            solve(cnt, index+1, board, fish);
            board[y][x] = prv;
            board[ny][nx] = number;
            fish[prv] = prvTemp;
            fish[number] = temp;
        }
        else{
            int prv = board[y][x];
            tuple<int, int, int> prvTemp = fish[prv];
            fish[prv] = {ny, nx, nd};
            swap(board[y][x], board[ny][nx]);
            solve(cnt, index+1, board, fish);
            swap(board[y][x], board[ny][nx]);
            fish[prv] = prvTemp;
        }
        
        return;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> board(4, vector<int>(4, 0));
    vector<tuple<int, int, int>> fish(17);
    for(int y=0; y<4; y++){
        for(int x=0; x<4; x++){
            int num, d;
            cin >> num >> d;
            board[y][x] = num;
            fish[num] = {y, x, d-1};
        }
    }

    answer = board[0][0];
    fish[0] = fish[board[0][0]];
    fish[board[0][0]] = {-1, -1, -1};
    board[0][0] = 0;
    solve(answer, 1, board, fish);

    cout << answer;
    return 0;
}