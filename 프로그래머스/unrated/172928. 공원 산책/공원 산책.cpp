#include <bits/stdc++.h>

using namespace std;
int board[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int d, y, x;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[0].size(); j++){
            if(park[i][j] == 'X') board[i][j] = 1;
            else if(park[i][j] == 'S'){
                y = i; x = j;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        if(routes[i][0] == 'N') d = 0;
        else if(routes[i][0] == 'S') d = 1;
        else if(routes[i][0] == 'W') d = 2;
        else if(routes[i][0] == 'E') d = 3;
        int cnt = routes[i][2] - '0';
        bool chk = false;
        int ny = y;
        int nx = x;
        while(cnt--){
            ny += dy[d];
            nx += + dx[d];
            if(ny < 0 || nx < 0 || ny >= park.size() || nx >= park[0].size() || board[ny][nx]){
                chk = true;
                break;
            }
        }
        if(!chk){
            y = ny;
            x = nx;  
        }
    }
    return {y, x};
}