class Solution {
public:

    void getPar(vector<string> &answer, string str, int o, int c){
        if(o < 0 || c < 0) return ;
        if(o > c) return ;
        if(o == 0 && c == 0){
            answer.push_back(str);
            return ;
        }

        getPar(answer, str + ")", o, c-1);
        getPar(answer, str + "(", o-1, c);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string str = "(";
        getPar(answer, str, n-1, n);
        return answer;
    }
};