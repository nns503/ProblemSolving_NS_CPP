#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector<vector<int>> &board){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            dp[y][x] = max(dp[y][x-1], dp[y-1][x]) + board[y][x];
        }
    }

    return dp[n][m];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(m+1));

    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            cin >> board[y][x];
        }
    }

    cout << solve(n, m, board);

    return 0;
}