#include <bits/stdc++.h>

using namespace std;

char mark[8] = {'R', 'M', 'A', 'F', 'N', 'T', 'J', 'C'};
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int solution(int m, int n, vector<string> board) {
        int answer = 0;
        bool boom = true;
        while(boom){
            vector<string> temp(board);
            boom = false;
            for(int x=0; x<n-1; x++){
                for(int y=0; y<m-1; y++){
                    char cur = board[y][x];
                    if(cur == '.') continue;
                    if(board[y][x+1] != cur) continue;
                    if(board[y+1][x] != cur) continue;
                    if(board[y+1][x+1] != cur) continue;
                    temp[y][x] = '.';
                    temp[y][x+1] = '.';
                    temp[y+1][x] = '.';
                    temp[y+1][x+1] = '.';
                    boom = true;
                }
            }
            board = temp;
            for(int x=0; x<n; x++){
                for(int y=m-1; y>=1; y--){
                    if(board[y][x] != '.') continue;
                    for(int k=y-1; k>=0; k--){
                        if(board[k][x] != '.'){
                            board[y][x] = board[k][x];
                            board[k][x] = '.';
                            break;
                        }
                    }
                }
            }
        }
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                if(board[y][x] == '.') answer++;
            }
        }
        return answer;
}