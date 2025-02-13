#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<int> arr(number.size(), 0x3f3f3f3f);
    stack<pair<char, int>> stk;
    for(int i=0; i<number.size(); i++){
        auto num = number[i];
        if(stk.empty()){
            stk.push({num, i});
            continue;
        }
        while(!stk.empty() && stk.top().A < num){
            auto cur = stk.top(); stk.pop();
            arr[cur.B] = i - cur.B;
        }
        stk.push({num, i});
    }
    
    for(int i=0; i<number.size(); i++){
        auto len = arr[i];
        if(len <= k){
            k--;
        }
        else{
            answer.push_back(number[i]);
        }
    }
    while(k > 0){
        k--;
        answer.pop_back();
    }
    return answer;
}