class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);

        for(int i=2; i<=n; i++){
            dp[i-1] = max(i-1, dp[i-1]);
            for(int k=1; k<=i/2; k++){
                dp[i] = max(dp[i], dp[k] * dp[i-k]);
            }
        }

        return dp[n];
    }
};
