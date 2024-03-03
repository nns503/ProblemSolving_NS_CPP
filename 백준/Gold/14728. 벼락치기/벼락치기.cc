#include <bits/stdc++.h>

using namespace std;

int n, t;
int dp[101][10001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    for(int i=1; i<=n; i++){
        int k, s;
        cin >> k >> s;
        for(int j=0; j<k; j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j=k; j<=10000; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-k] + s);
        }  
    }

    cout << dp[n][t];
    return 0;
}