#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    vector<vector<int>> dp(10001, vector<int>(4, 0));

    cin >> T;
    dp[1][0] = 1, dp[1][1] = 1;
    dp[2][0] = 2, dp[2][1] = 1, dp[2][2] = 1;
    dp[3][0] = 3, dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;

    for(int i=4; i<=10000; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][2] + dp[i-2][1];
        dp[i][3] = dp[i-3][3] + dp[i-3][2] + dp[i-3][1];
        dp[i][0] = dp[i][1] + dp[i][2] + dp[i][3];
    }
    int n;

    while(T--){
        cin >> n;
        cout << dp[n][0] << '\n';
    }

    return 0;
}