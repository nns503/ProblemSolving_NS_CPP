#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scov, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto cur : scov){
        pq.push(cur);
    }
    
    while(pq.size() >= 2){
        auto cur = pq.top(); pq.pop();
        if(cur >= k) break;
        auto nxt = pq.top(); pq.pop();
        pq.push(cur + nxt * 2);
        answer++;
    }
    
    if(pq.size() <= 1){
        auto cur = pq.top();
        if(cur < k) return -1;
    }
    return answer;
}