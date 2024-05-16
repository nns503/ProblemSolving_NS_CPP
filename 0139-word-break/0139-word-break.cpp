class Solution {
public:

    bool func(string s, unordered_set<string> &word, int n, unordered<string, bool> dp){
        if(s.size() == 0){
            return true;
        }

        if(dp.find(s) == dp.end()) return dp[s];

        for(int i=0; i<s.size(); i++){
            string str = s.substr(0, i+1);
            if(word.find(str) != word.end()){
                dp[str] = true;
                if(func(s.substr(i+1), word, i+1, n, dp)) return true;
            }
            else df[str] = false;
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        unordered_set<string> word;
        
        for(auto cur : wordDict){
            word.insert(cur);
        }
        return func(s, word, 0, n);
   
    }
};