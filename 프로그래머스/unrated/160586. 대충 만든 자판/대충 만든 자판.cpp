#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> m;
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int cnt=0; cnt<keymap.size(); cnt++){
        for(int i=0; i<keymap[cnt].size(); i++){
            char cur = keymap[cnt][i];
            if(m.find(cur) == m.end()){
                m[cur] = i+1;
            }
            else{
                if(m[cur] > i+1) m[cur] = i+1;
            }
        }
    }
    
    for(int cnt=0; cnt<targets.size(); cnt++){
        int temp = 0;
        int chk = false;
        for(int i=0; i<targets[cnt].size(); i++){
            char cur = targets[cnt][i];
            if(m.find(cur) == m.end()){
                answer.push_back(-1);
                chk= true;
                break;
            }
            else{
                temp += m[cur];
            }
        }
        if(chk) continue;
        answer.push_back(temp);
    }
    return answer;
}