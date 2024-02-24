#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;
int line[501];
int dp[501];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        line[a] = b;
    }

    for(int i=1; i<=500; i++){
        if(line[i] == 0) continue;
        dp[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(line[j] == 0) continue;
            if(line[j] > line[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << n - *max_element(dp, dp+501);
    return 0;
}