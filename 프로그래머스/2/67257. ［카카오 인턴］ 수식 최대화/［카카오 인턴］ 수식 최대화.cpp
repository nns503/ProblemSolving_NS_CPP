#include <bits/stdc++.h>

using namespace std;

long long cal(char op, long long a, long long b){
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    return a+b;
}

long long solve(string exp, vector<char> &op){
    long long sum = 0;
    deque<long long> number;
    queue<char> q;
    int st = 0;
    for(int i=0; i<exp.size(); i++){
        if(exp[i] >= '0' && exp[i] <= '9') continue;
        string cur = exp.substr(st, i - st);
        number.push_back(stoll(cur));
        q.push(exp[i]);
        st = i+1;
    }
    string lastNumber = exp.substr(st, exp.size() - st);
    number.push_back(stoll(lastNumber));
    
    
    for(int i=0; i<=2; i++){
        auto curOp = op[i];
        int cnt = q.size();
        while(cnt--){
            auto cur = q.front(); q.pop();
            if(cur == curOp){
                long long a = number.front(); number.pop_front();
                long long b = number.front(); number.pop_front();
                long long result = cal(cur, a, b);
                number.push_front(result);
            }
            else{
                q.push(cur);
                long long a = number.front(); number.pop_front();
                number.push_back(a);
            }
        }
        long long x = number.front(); number.pop_front();
        number.push_back(x);
    }
    return abs(number.front());
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> op = {'*', '+', '-'};
    sort(op.begin(), op.end());
    do{
        answer = max(solve(expression, op), answer);
    }while(next_permutation(op.begin(), op.end()));
    
    return answer;
}