#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    int ans = arr[1];
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-2][0] + arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans;
    
    return 0;
}