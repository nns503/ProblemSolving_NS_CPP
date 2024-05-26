class Solution {
public:
    bool solve(string &s, string &p, int a, int b, vector<vector<int>> &memo){
        if(a >= s.size() || b >= p.size()){
            if(a >= s.size()){
                for(int i=b; i<p.size(); i++){
                    if(p[i] != '*') return false;
                }
                return true;
            } 
            return false;
        }

        if(memo[a][b] != -1) return memo[a][b];

        if(s[a] == p[b] || p[b] == '?'){
            return memo[a][b] = solve(s, p, a+1, b+1, memo);
        }
        else if(p[b] == '*'){
            return memo[a][b] = (solve(s, p, a+1, b, memo) || solve(s, p, a, b+1, memo));
        }
        return memo[a][b] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return solve(s, p, 0, 0, memo);
    }
};