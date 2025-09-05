#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &cost, vector<int> &happy){
    vector<vector<int>> dp(n+1, vector<int>(101, 0));

    for(int i=1; i<=n; i++){
        int curCost = cost[i-1];
        int curHappy = happy[i-1]; 
        for(int k=100; k>=0; k--){
            if(k-curCost <= 0){
                dp[i][k] = dp[i-1][k];
            } 
            else{
                dp[i][k] = max(dp[i-1][k], dp[i-1][k-curCost] + curHappy);
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=100; i++){
        answer = max(answer, dp[n][i]);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> cost(n);
    for(auto &cur: cost){
        cin >> cur;
    }

    vector<int> happy(n);
    for(auto &cur: happy){
        cin >> cur;
    }

    cout << solve(n, cost, happy);

    return 0;
}