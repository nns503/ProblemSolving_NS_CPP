#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000003;
long long dp[2][1001][1001];

long long solve(int n, int k, int st){
    if(st == 0 && k == 0){
        return 1;
    }
    if(st == 1 && k == 0){
        if(n >= 0) {
            return 1;
        }
        return 0;
    }
    if(n <= 0){
        return 0;
    }
    if(dp[st][n][k] != -1){
        return dp[st][n][k];
    }

    dp[st][n][k] = 0;
    dp[st][n][k] += solve(n-1, k, st) % MOD;
    dp[st][n][k] += solve(n-2, k-1, st) % MOD;
    dp[st][n][k] %= MOD;
    
    return dp[st][n][k];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    long long answer = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<=1000; j++){
            for(int k=0; k<=1000; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    answer += solve(n-1, k, 0);
    answer += solve(n-2, k-1, 1);

    cout << answer % MOD;
    return 0;
}