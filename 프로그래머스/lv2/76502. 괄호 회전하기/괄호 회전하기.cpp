#include <bits/stdc++.h>

using namespace std;

string v;

bool isFunc(){
    stack<char> st;
    for(char a : v){
        if(a == '[' || a == '(' || a == '{') st.push(a);
        else if( a == ']'){
            if(!st.empty() && st.top() == '[') st.pop();
            else return false;
        }
        else if( a == ')'){
            if(!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
        else if( a == '}'){
            if(!st.empty() && st.top() == '{') st.pop();
            else return false;
        }
    }
    return st.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;
    int cnt = s.size();
    if(cnt == 1) return 0;
    while(cnt--){
        v = s;
        if(isFunc()) answer++;
        s = v.substr(1);
        s.push_back(v[0]);
    }
    return answer;
}