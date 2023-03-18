#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    for(auto a : s){
        answer.push_back(a-'0');
    }
    return answer;
}