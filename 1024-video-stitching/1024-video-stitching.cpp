class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(101, 0x3f3f3f3f);
        
        sort(clips.begin(), clips.end());

        dp[0] = 0;
        for(auto cur : clips){
            int start = cur[0];
            int end = cur[1];
            for(int i=start+1; i<=end; i++){
                dp[i] = min(dp[start] + 1, dp[i]);
            }
        }

        return (dp[time] == 0x3f3f3f3f ? -1 : dp[time]); 
    }
};