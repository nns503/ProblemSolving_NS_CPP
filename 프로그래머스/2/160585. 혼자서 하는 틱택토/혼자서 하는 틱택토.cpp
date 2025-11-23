#include <bits/stdc++.h>

using namespace std;

set<vector<string>> TTT;

bool existBoard(vector<string> board){
    if(TTT.find(board) == TTT.end()){
        return false;
    }
    return true;
}

bool checkWin(vector<string> board, int y, int x){
    bool chk = false;
    char cur = board[y][x];
    int yCnt = 0;
    int xCnt = 0;
    
    for(int i=0; i<3; i++){
        if(board[y][i] == cur) yCnt++;
        if(board[i][x] == cur) xCnt++;
    }
    if(yCnt == 3 || xCnt == 3) chk = true;
    if(board[1][1] == cur && board[0][0] == board[1][1] && board[0][0] == board[2][2]) chk = true;
    if(board[1][1] == cur && board[2][0] == board[1][1] && board[2][0] == board[0][2]) chk = true;
    
    return chk;
}

void play(vector<string> board, int cnt, bool t){
    if(cnt == 9){
        return ;
    }
    
    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++){
            if(board[y][x] != '.') continue;
            
            if(t) board[y][x] = 'O';
            else board[y][x] = 'X';
            
            if(!existBoard(board)){
                TTT.insert(board);
                if(!checkWin(board, y, x)) play(board, cnt+1, (t != true));
            }
            
            board[y][x] = '.';
        }
    }
}

void init(){
    vector<string> board(3);
    for(auto &cur : board){
        cur = "...";
    }
    TTT.insert(board);
    play(board, 0, true);
}

int solution(vector<string> board) {
    init();
    return existBoard(board);
}