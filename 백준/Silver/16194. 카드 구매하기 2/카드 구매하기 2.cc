#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dp+1, dp+1001, 0x3f3f3f3f);
    
    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];

    for(int i=1; i<=n; i++){
        for(int j=0; j+i<=n; j++){
            dp[i+j] = min(dp[i+j], arr[i] + dp[j]);
        }
    }

    cout << dp[n];
    return 0;
}