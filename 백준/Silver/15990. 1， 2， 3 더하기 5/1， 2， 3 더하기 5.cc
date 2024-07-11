#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000009;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<vector<int>> dp(100001, vector<int>(4, 0));
    dp[1][1] = 1; dp[1][0] = 1;
    dp[2][2] = 1; dp[2][0] = 1;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1; dp[3][0] = 3;
    for(int i=4; i<=100000; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
        dp[i][0] = ((dp[i][1] + dp[i][2]) % MOD + dp[i][3] ) % MOD;
    }
    while(T--){
        int n;
        cin >> n;
        
        cout << dp[n][0] << '\n';

    }
    return 0;
}