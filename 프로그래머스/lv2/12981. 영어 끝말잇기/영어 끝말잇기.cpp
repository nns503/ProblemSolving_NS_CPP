#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    s.insert(words[0]);
    for(int cnt=1; cnt<words.size(); cnt++){
        if(s.find(words[cnt]) != s.end() || words[cnt-1].back() != words[cnt][0]){
            answer.push_back(cnt%n + 1);
            answer.push_back(cnt/n + 1);
            return answer;                    
        }
        else{
            s.insert(words[cnt]);
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}