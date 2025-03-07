#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int h, w;

int dy[2] = {0, -1};
int dx[2] = {-1, 0};

bool OOB(int y, int x){
    return (y < 1 || x < 1 || y > h || x > w);
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    h = n;
    w = m;
    vector<vector<bool>> board(n+1, vector<bool>(m+1, false));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(auto point : puddles){
        board[point[1]][point[0]] = true;
    }
    
    dp[1][1] = 1;
    for(int y=1; y<=h; y++){
        for(int x=1; x<=w; x++){
            if(board[y][x]) continue;
            for(int i=0; i<2; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(OOB(ny, nx)) continue;
                dp[y][x] = (dp[y][x] + dp[ny][nx]) % MOD;
            }
        }
    }
    
    return dp[h][w];
}