#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &arr){
    vector<int> dp(n+1, 0);
    dp[1] = arr[1];
    if(n >= 2) dp[2] = arr[1] + arr[2];
    if(n >= 3) dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    
    for(int i=4; i<=n; i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    }

    return dp[n];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << solve(n, arr);

    return 0;
}