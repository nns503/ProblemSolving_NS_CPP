#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    deque<int> dq;
    dq.push_back(0);
    for(int i=food.size()-1; i>=1; i--){
        while(food[i]>=2){
            food[i] -= 2;
            dq.push_front(i);
            dq.push_back(i);
        }
    }
    while(!dq.empty()){
        answer += to_string(dq.front());
        dq.pop_front();
    }
    return answer;
}