#include <bits/stdc++.h>

using namespace std;

int checkChar(char c){
    if(c == ',' || c == ';') return 2;
    if(c == '*' || c == '[' || c == ']' || c == '&') return 1;
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    int st = 0;
    string prefix;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            st = i+1;
            prefix = str.substr(0, i);
            break;
        }
    }

    vector<string> answer;

    int p = st;
    int s = 0;
    stack<char> stk;
    for(int i=st; i<str.size(); i++){
        int flag = checkChar(str[i]);
        if(flag == 2){
            string ans = prefix;
            while(!stk.empty()){
                ans += stk.top();
                stk.pop();
            }
            ans += " ";
            ans += str.substr(p, s);
            ans += ";";
            p = i+2;
            i++;
            s = 0;
            answer.push_back(ans);
        }
        if(flag == 1){
            if(str[i] == '&'){
                stk.push('&');
            }
            if(str[i] == '['){
                stk.push(']');
            }
            if(str[i] == ']'){
                stk.push('[');
            }
            if(str[i] == '*'){
                stk.push('*');
            }
        }
        if(flag == 0){
            s++;
        }
    }
    
    for(auto cur : answer){
        cout << cur << '\n';
    }
}