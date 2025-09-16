#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(auto cur : works){
        pq.push(cur);
    }
    
    while(n-- > 0){
        auto cur = pq.top(); pq.pop();
        if(cur == 0) break;
        pq.push(cur-1);
    }
    
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        answer += cur * cur;
    }
    
    return answer;
}