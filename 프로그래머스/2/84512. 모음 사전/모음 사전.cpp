#include <bits/stdc++.h>

using namespace std;

int cnt = 1;
map<string, int> m;
vector<char> alp = {'A', 'E', 'I', 'O', 'U'};

void solve(string target, string word){
    if(word.size() >= 5) return;
    
    for(int i=0; i<alp.size(); i++){
        word.push_back(alp[i]);
        m[word] = cnt++;
        solve(target, word);
        word.pop_back();
    }
}

int solution(string word) {
    solve(word, "");
    
    return m[word];
}