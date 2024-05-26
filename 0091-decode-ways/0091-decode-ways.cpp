class Solution {
public:

    int solve(string s, int n, int p, unordered_map<int, int> &memo){
        if(p >= n){
            return 1;
        }

        if(memo.find(p) != memo.end()) return memo[p];
        char cur = s[p];
        int cnt = 0;
        if(cur != '0') cnt += solve(s, n, p+1, memo);
        if(cur == '1'){
            if(p != n-1){
                cnt += solve(s, n, p+2, memo);
            }
        }
        else if(cur == '2'){
            if(p != n-1 && s[p+1] <= '6'){
                cnt += solve(s, n, p+2, memo);
            }
        }
        return memo[p] = cnt;
    }

    int numDecodings(string s) {
        int n = s.size();
        unordered_map<int, int> memo;
        return solve(s, n, 0, memo);
    }
};