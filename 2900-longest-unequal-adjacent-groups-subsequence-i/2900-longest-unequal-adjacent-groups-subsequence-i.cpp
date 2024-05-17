class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> answer;
        answer.push_back(words[0]);
        int p = 0;
        for(int i=1; i<words.size(); i++){
            if(groups[p] != groups[i]){
                answer.push_back(words[i]);
                p = i;
            } 
        }

        return answer;
    }
};