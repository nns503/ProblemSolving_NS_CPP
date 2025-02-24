#include <bits/stdc++.h>

using namespace std;

int board[201][201];

void initBoard(int n){
    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            if(y == x) board[y][x] = 0;
            else board[y][x] = 100000000;
        }
    }
}

void setBoard(vector<vector<int>> &fares, int n){
    for(auto cur : fares){
        board[cur[0]][cur[1]] = cur[2];
        board[cur[1]][cur[0]] = cur[2];
    }
    
    for(int k=1; k<=n; k++){
        for(int y=1; y<=n; y++){
            for(int x=1; x<=n; x++){
                if(board[y][k] + board[k][x] < board[y][x]){
                    board[y][x] = board[y][k] + board[k][x];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0x3f3f3f3f;
    initBoard(n);
    setBoard(fares, n);

    
    for(int i=1; i<=n; i++){
        int sum = 0;
        sum += board[s][i];
        sum += board[i][a];
        sum += board[i][b];
        answer = min(answer, sum);
    }
    return answer;
}

// 2025-02-24, 16:35