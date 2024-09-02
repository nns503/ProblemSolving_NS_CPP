#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> arr[d+1];    

    for(int i=0; i<n; i++){
        int st, en, len;
        cin >> st >> en >> len;
        if(en > d) continue;
        arr[en].push_back({st, len});
    }

    vector<int> dp(d+1, 0);

    for(int i=1; i<=d; i++){
        dp[i] = dp[i-1] + 1;
        for(auto cur : arr[i]){
            dp[i] = min(dp[cur.A] + cur.B, dp[i]);
        }
    }

    cout << dp[d];

    return 0;
}