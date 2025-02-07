#include <bits/stdc++.h>

using namespace std;

string str;

int getScore(char c){
    if(c == 'C') return 12;
    if(c == 'O') return 16;
    return 1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;

    int answer = 0;
    stack<int> stk;
    for(int i=0; i<str.size(); i++){
        auto cur = str[i];
        if(cur == '('){
            stk.push(-1);
        }
        else if(cur == ')'){
            int temp = 0;
            while(!stk.empty() && stk.top() != -1){
                temp += stk.top();
                stk.pop();
            }
            if(!stk.empty() && stk.top() == -1) stk.pop();
            stk.push(temp);
        }
        else if(cur >= '2' && cur <= '9'){
            int mul = cur - '0';
            int temp = stk.top(); stk.pop();
            stk.push(temp * mul);
        }
        else{
            stk.push(getScore(cur));
        }
    }

    while(!stk.empty()){
        answer += stk.top(); stk.pop();
    }

    cout << answer;

    return 0;
}