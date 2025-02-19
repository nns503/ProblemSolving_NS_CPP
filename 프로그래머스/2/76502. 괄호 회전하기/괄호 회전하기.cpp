#include <bits/stdc++.h>

using namespace std;

bool solve(string str){
    stack<char> stk;
    for(auto cur : str){
        if(cur == '[' || cur == '(' || cur == '{'){
            stk.push(cur);
        }
        else{
            if(stk.empty()) return false;
            auto t = stk.top(); stk.pop();
            if(t == '[' && cur != ']') return false;
            if(t == '(' && cur != ')') return false;
            if(t == '{' && cur != '}') return false;
        }
    }
    if(!stk.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        answer += solve(s);
        auto temp = s[0];
        s = s.substr(1) + temp;
    }
    return answer;
}