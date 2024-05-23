class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++) m[s[i]] = i;
        
        unordered_map<char, bool> vis;
        stack<char> stk;

        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(vis[c]) continue;
    
            while(!stk.empty()){
                char nxt = stk.top();
                if(m[nxt] <= i) break;
                if(nxt < c) break;
                vis[nxt] = false;
                stk.pop();
            }

            stk.push(c);
            vis[c] = true;
            
        }

        
        string answer = "";
        while(!stk.empty()){
            answer.push_back(stk.top()); stk.pop();
        }
        reverse(answer.begin(), answer.end());

        return answer;
    }
};