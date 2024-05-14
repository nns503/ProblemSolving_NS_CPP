class Solution {
public:

    void func(vector<int> &dp, int x, int y){
        if(x == y) return;

        if(x % 11 == 0 && dp[x / 11] > dp[x] + 1){
            dp[x / 11] = dp[x] + 1;
            func(dp, x/11, y);
        }
        if(x % 5 == 0 && dp[x / 5] > dp[x] + 1){
            dp[x / 5] = dp[x] + 1;
            func(dp, x/5, y);
        }

        if(x+1 <= 10000 && dp[x+1] > dp[x] + 1){
            dp[x+1] = dp[x] + 1;
            func(dp, x+1, y);
        }
        if(x-1 >= 1 && dp[x-1] > dp[x] + 1){
            dp[x-1] = dp[x] + 1;
            func(dp, x-1, y);
        }        
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp(10001, 0x3f3f3f3f);
        dp[x] = 0;
        func(dp, x, y); 
        return dp[y];   
    }
};