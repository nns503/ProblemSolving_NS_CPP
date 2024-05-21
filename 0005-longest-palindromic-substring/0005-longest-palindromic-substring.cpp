class Solution {
public:

    string longestPalindrome(string s) {
        int len = s.size();
        string answer = "";
        answer.push_back(s[0]);
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        for(int i=0; i<len; i++) dp[i][i] = true;

        for(int i=1; i<len; i++){
            for(int j=0; j<len-i; j++){
                bool flag = true;
                if(s[j] == s[j+i]){
                    for(int k=1; k<=i/2; k++){
                        if(!dp[j+k][j+i-k]){
                            flag = false;
                            break;
                        }
                    }
                }
                else flag = false;

                dp[j][j+i] = flag;
                if(flag && answer.size() < i+1){
                    answer = s.substr(j, i+1);
                }
            }
        }
        return answer;
    }


};

