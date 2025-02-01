#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> op) {
    vector<int> answer;
    priority_queue<int> mxQ;
    priority_queue<int, vector<int>, greater<int>> mnQ;
    map<int, int> numbers;
    
    for(auto cur : op){
        int number = stoi(cur.substr(2));
        if(cur[0] == 'I'){
            mxQ.push(number);
            mnQ.push(number);
            numbers[number]++;
        }
        else{
            if(number == 1){
                while(!mxQ.empty()){
                    auto num = mxQ.top(); mxQ.pop();
                    if(numbers[num] == 0) continue;
                    numbers[num]--;
                    break;
                }
            }
            else if(number == -1){
                while(!mnQ.empty()){
                    auto num = mnQ.top(); mnQ.pop();
                    if(numbers[num] == 0) continue;
                    numbers[num]--;
                    break;
                }
            }
        }
    }
    
    while(!mxQ.empty() && numbers[mxQ.top()] == 0){
        mxQ.pop();
    }
    
    while(!mnQ.empty() && numbers[mnQ.top()] == 0){
        mnQ.pop();
    }
    
    if(mxQ.empty()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(mxQ.top());
    answer.push_back(mnQ.top());
    
    return answer;
}