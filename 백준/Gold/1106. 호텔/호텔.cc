#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dp[21][1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> arr(n+1, {0, 0});
    for(int i=1; i<=n; i++){
        cin >> arr[i].Y >> arr[i].X;
    }

    for(int i=1; i<=c; i++){
        dp[0][i] = 0x3f3f3f3f;
    }

    for(int i=1; i<=n; i++){
        int cost, human;
        tie(cost, human) = arr[i];
        
        for(int x=0; x<=c; x++){
            dp[i][x] = dp[i-1][x];
        }

        for(int x=0; x<=c; x++){
            int prv = (x-human < 0 ? 0 : x-human);
            dp[i][x] = min(dp[i-1][x], dp[i][prv] + cost);
        }
    }


    cout << dp[n][c];
    return 0;
}