#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size()/2;
    if(!(s.size() % 2)){
        answer.push_back(s[len-1]);
    }
    answer.push_back(s[len]);
    return answer;
}