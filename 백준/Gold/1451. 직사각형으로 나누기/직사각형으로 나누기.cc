#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    vector<vector<long long>> sum(n+1, vector<long long>(m+1, 0));
    for(auto &cur : board) cin >> cur;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            int cur = board[y][x] - '0';
            sum[y+1][x+1] = cur + sum[y+1][x] + sum[y][x+1] - sum[y][x];
        }
    }

    long long answer = -1;

    if(n >= 3){
        for(int i=1; i<=n-2; i++){
            for(int j=i+1; j<=n-1; j++){
                long long temp = sum[i][m] * (sum[j][m] - sum[i][m]) * (sum[n][m] - sum[j][m]);
                answer = max(temp, answer);
            }
        }
    }

    if(m >= 3){
        for(int i=1; i<=m-2; i++){
            for(int j=i+1; j<=m-1; j++){
                long long temp = sum[n][i] * (sum[n][j] - sum[n][i]) * (sum[n][m] - sum[n][j]);
                answer = max(temp, answer);
            }
        }
    }

    if(n >= 2){
        for(int y=1; y<=n-1; y++){
            for(int i=1; i<=m-1; i++){
                long long temp = sum[y][i] * (sum[y][m] - sum[y][i]) * (sum[n][m] - sum[y][m]); 
                answer = max(temp, answer);
            }
        }

        for(int y=1; y<=n-1; y++){
            for(int i=1; i<=m-1; i++){
                long long temp = (sum[n][i] - sum[y][i]) * 
                    ((sum[n][m] - sum[y][m]) - (sum[n][i] - sum[y][i])) * 
                    (sum[y][m]); 
                answer = max(temp, answer);
            }
        }
    }

    if(m >= 2){
        for(int x=1; x<=m-1; x++){
            for(int i=1; i<=n-1; i++){
                long long temp = sum[i][x] * (sum[n][x] - sum[i][x]) * (sum[n][m] - sum[n][x]); 
                answer = max(temp, answer);
            }
        }

        for(int x=1; x<=m-1; x++){
            for(int i=1; i<=n-1; i++){
                long long temp = (sum[i][m] - sum[i][x]) * 
                ((sum[n][m] - sum[n][x]) - (sum[i][m] - sum[i][x])) * 
                (sum[n][x]); 
                answer = max(temp, answer);
            }
        }
    }
    cout << answer;
    return 0;
}