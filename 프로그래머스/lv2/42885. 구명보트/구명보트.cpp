#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    deque<int> dq;
    for(auto a : people) dq.push_back(a);
    
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        if(!dq.empty() && dq.back() + cur <= limit) dq.pop_back();
        answer++;
    }

    
    return answer;
}