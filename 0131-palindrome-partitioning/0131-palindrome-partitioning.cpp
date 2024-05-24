class Solution {
public:

    void solve(string &s, int n, int p, 
        vector<vector<bool>> &tb, vector<string> &temp, vector<vector<string>> &answer){
        if(n == p){
            answer.push_back(temp);
            return;
        }
        for(int i=p; i<n; i++){
            if(tb[p][i]){
                temp.push_back(s.substr(p, i-p+1));
                solve(s, n, i+1, tb, temp, answer);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> answer;
        vector<vector<bool>> tb(n, vector<bool>(n, true));

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=0; k<(j-i+1)/2; k++){
                    if(s[i+k] != s[j-k]){
                        tb[i][j] = false;
                        break;
                    }
                }
            }
        }

        vector<string> temp;
        solve(s, n, 0, tb, temp, answer);
        return answer;
    }
};