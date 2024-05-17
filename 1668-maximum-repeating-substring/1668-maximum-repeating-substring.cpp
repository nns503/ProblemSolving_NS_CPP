class Solution {
public:
    int solve(string seq, string word, int index, vector<int> &memo){
        int answer = 0;
        for(int i=0; i<=seq.size() - word.size(); i++){
            string str = seq.substr(i, word.size());
            if(str == word){
                memo[i]++;
                if(i >= word.size()) memo[i] += memo[i - word.size()];
            }
            answer = max(answer, memo[i]);
        }

        return answer;
    }
    int maxRepeating(string seq, string word) {
        if(word.size() > seq.size()) return 0;
        vector<int> memo(seq.size(), 0);
        return solve(seq, word, 0, memo);   
    }
};