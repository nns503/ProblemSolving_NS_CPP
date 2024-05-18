class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        int MOD = pow(10, 9) + 7;
        dp[0] = 1;

        for(int i=1; i<=high; i++){
            if(i >= zero){
                dp[i] += dp[i - zero];
            }
            if(i >= one){
                dp[i] += dp[i - one];
            }
            dp[i] %= MOD;
        }
        int answer = 0;
        for(int i=low; i<=high; i++){
            answer += dp[i];
            answer %= MOD;
        }

        return answer;
    }
};