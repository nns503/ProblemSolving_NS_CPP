#include <bits/stdc++.h>

using namespace std;

int cnt[26];
vector<int> solution(string s) {
    vector<int> answer;
    fill(cnt, cnt+26, -1);
    for(int i=0; i<s.size(); i++){
        (cnt[s[i]-'a'] == -1) ? answer.push_back(-1) : answer.push_back(i - cnt[s[i]-'a']);
        cnt[s[i]-'a'] = i;
    }
    return answer;
}