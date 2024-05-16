class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> dp(rowIndex+1);

        for(int i=0; i<=rowIndex; i++){
            vector<int> temp(i+1, 0);
            for(int j=0; j<i+1; j++){
                if(j == 0 || j == i) temp[j] = 1;
                else{
                    temp[j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
            dp[i] = temp;
        }      

        return dp[rowIndex];
    }
};