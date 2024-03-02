#include <bits/stdc++.h>

using namespace std;

int board[21][21];
int n, answer;

int findMax(){
    int findNum = -1;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            findNum = max(findNum, board[y][x]);
        }
    }
    return findNum;
}

void func(int cnt){
    if(cnt == 5){
        answer = max(findMax(), answer);
        return;
    }

    int savedBoard[21][21];
    
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            savedBoard[y][x] = board[y][x];
        }
    }
    
    for(int i=0; i<4; i++){
        if(i == 0){
            for(int y=0; y<n; y++){
                int st = 0;
                for(int x=0; x<n; x++){
                    if(x == st) continue;
                    if(board[y][x] == 0) continue;
                    if(board[y][st] == 0){
                        board[y][st] = board[y][x];
                        board[y][x] = 0;
                    }
                    else if(board[y][st] == board[y][x]){
                        board[y][st] += board[y][x];
                        board[y][x] = 0;
                        st++;
                    }
                    else{
                        st++;
                        x--;
                    }
                }
            }
        }
        else if(i == 1){
            for(int y=0; y<n; y++){
                int st = n-1;
                for(int x=n-1; x>=0; x--){
                    if(x == st) continue;
                    if(board[y][x] == 0) continue;
                    if(board[y][st] == 0){
                        board[y][st] = board[y][x];
                        board[y][x] = 0;
                    }
                    else if(board[y][st] == board[y][x]){
                        board[y][st] += board[y][x];
                        board[y][x] = 0;
                        st--;
                    }
                    else{
                        st--;
                        x++;
                    }
                }
            }
        }
        else if(i == 2){
            for(int x=0; x<n; x++){
                int st = 0;
                for(int y=0; y<n; y++){
                    if(y == st) continue;
                    if(board[y][x] == 0) continue;
                    if(board[st][x] == 0){
                        board[st][x] = board[y][x];
                        board[y][x] = 0;
                    }
                    else if(board[st][x] == board[y][x]){
                        board[st][x] += board[y][x];
                        board[y][x] = 0;
                        st++;
                    }
                    else{
                        st++;
                        y--;
                    }
                }
            }
        }
        else if(i == 3){
            for(int x=0; x<n; x++){
                int st = n-1;
                for(int y=n-1; y>=0; y--){
                    if(y == st) continue;
                    if(board[y][x] == 0) continue;
                    if(board[st][x] == 0){
                        board[st][x] = board[y][x];
                        board[y][x] = 0;
                    }
                    else if(board[st][x] == board[y][x]){
                        board[st][x] += board[y][x];
                        board[y][x] = 0;
                        st--;
                    }
                    else{
                        st--;
                        y++;
                    }
                }
            }
        }

        func(cnt+1);

        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                board[y][x] = savedBoard[y][x];
            }
        }        
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    func(0);

    cout << answer;
    
    return 0;
}