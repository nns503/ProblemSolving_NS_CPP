#include <bits/stdc++.h>

using namespace std;

long long solve(int n){
    vector<long long> dp(10, 1);
    vector<long long> sum(n+1, 0);
    
    sum[1] = 10;

    for(int i=2; i<=n; i++){
        for(int num=9; num>=0; num--){
            for(int k=0; k<num; k++){
                dp[num] += dp[k];
            }
        }
        
        for(int num=0; num<=9; num++){
            sum[i] += dp[num];
        }
    }

    return sum[n];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}