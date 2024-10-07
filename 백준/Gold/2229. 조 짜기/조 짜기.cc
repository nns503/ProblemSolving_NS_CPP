#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> score(n+1, 0);
    for(int i=1; i<=n; i++) cin >> score[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        int mx = score[i];
        int mn = score[i];
        int prv = dp[0][i-1];
        for(int j=i; j<=n; j++){
            mx = max(mx, score[j]);
            mn = min(mn, score[j]);
            dp[i][j] = max(dp[i-1][i-1] + mx - mn, dp[i-1][j]);
        }
    }

    cout << dp[n][n];
    return 0;
}