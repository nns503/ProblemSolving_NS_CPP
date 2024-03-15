#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> m;
string solution(vector<string> sv, vector<int> ch) {
    string answer = "";
    
    for(int i=0; i<sv.size(); i++){
        string cur = sv[i];
        int score = ch[i];
        if(score == 4) continue;
        else if(score < 4){
            m[cur[0]] += 4 - score;
        }
        else if(score > 4){
            m[cur[1]] += score - 4;
        }
    }
    
    if(m['R'] >= m['T']) answer.push_back('R');
    else answer.push_back('T');
    
    if(m['C'] >= m['F']) answer.push_back('C');
    else answer.push_back('F');
    
    if(m['J'] >= m['M']) answer.push_back('J');
    else answer.push_back('M');
    
    if(m['A'] >= m['N']) answer.push_back('A');
    else answer.push_back('N');
   
    return answer;
}