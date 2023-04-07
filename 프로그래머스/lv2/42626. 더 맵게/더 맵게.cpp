#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto a : scoville) pq.push(a);
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        if(cur < K){
            if(pq.empty()) return -1;
            int temp = pq.top() * 2; pq.pop();
            pq.push(cur+temp);
            answer++;
        }
    }
    return answer;
}