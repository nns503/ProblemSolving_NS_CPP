class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0x3f3f3f3f);
        dp[0] = 0;
        for(auto cur : coins){
            for(int i=cur; i<=amount; i++){
                dp[i] = min(dp[i-cur] + 1, dp[i]);
            }
        }
        return (dp[amount] == 0x3f3f3f3f ? -1 : dp[amount]);
    }
};