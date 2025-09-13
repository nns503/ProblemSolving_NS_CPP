#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(int a : works) pq.push(a);
    while(n-- && !pq.empty()){
        int cur = pq.top(); pq.pop();
        if(cur-1 != 0) pq.push(cur-1);
    }
    
    while(!pq.empty()){
        long long cur = pq.top(); pq.pop();
        answer += cur * cur;
    }
    return answer;
}