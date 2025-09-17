#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<players.size(); i++){
        auto cur = players[i];
        int d = cur / m;
        
        while(!pq.empty()){
            auto cur = pq.top();
            if(cur != i) break;
            pq.pop();
        }
        while(d > pq.size()){
            pq.push(i + k);
            answer++;
        }
    }
    
    return answer;
}