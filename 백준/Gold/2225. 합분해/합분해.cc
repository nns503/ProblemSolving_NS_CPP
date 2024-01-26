#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[201][201];
const int MOD = 1000000000;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for(int i=1; i<=200; i++){
        dp[1][i] = i;
        dp[i][1] = 1;
    }
    for(int i=2; i<=200; i++){
        for(int j=2; j<=200; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n][k];

    return 0;
}