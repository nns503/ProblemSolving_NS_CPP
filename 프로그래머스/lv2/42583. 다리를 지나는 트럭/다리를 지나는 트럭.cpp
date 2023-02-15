#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> stand;
    queue<int> bridge;
    
    for(auto a : truck_weights) stand.push(a);
    for(int i=0;i<bridge_length;i++) bridge.push(0);
    
    while(!stand.empty()){
        answer++;
        sum -= bridge.front();
        bridge.pop();
        if(sum+stand.front()<=weight){
            bridge.push(stand.front());
            sum += stand.front();
            stand.pop();
        }
        else bridge.push(0);
    }
    
    while(!bridge.empty()){
        answer++;
        bridge.pop();
    }
    
    return answer;
}