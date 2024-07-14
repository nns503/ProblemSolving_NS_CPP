#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;
vector<int> dp(100001, 0x3f3f3f3f);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i*i<=n; i++){
        num.push_back(i*i);
        dp[i*i] = 1;
    }

    for(int i=1; i<=n; i++){
        if(dp[i] != 0x3f3f3f3f) continue;
        for(int k=0; k<num.size(); k++){
            if(i - num[k] <= 0) break;
            dp[i] = min(dp[i-num[k]] + 1, dp[i]);
        }
    }

    cout << dp[n];
    return 0;
}