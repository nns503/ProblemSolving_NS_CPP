#include <bits/stdc++.h>

using namespace std;

stack<char> st;

bool solution(string s)
{
    bool answer = true;
    for(char a : s){
        if(a == '(') st.push(a);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}