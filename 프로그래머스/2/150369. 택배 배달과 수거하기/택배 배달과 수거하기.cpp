#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> d;
    stack<int> p;
    for(int i=0; i<deliveries.size(); i++){
        while(deliveries[i]--){
            d.push(i+1);
        }
    } 
    for(int i=0; i<pickups.size(); i++){
        while(pickups[i]--){
            p.push(i+1);
        }
    } 
    
    while(!d.empty() || !p.empty()){
        int mx = 0;
        int dcap = cap;
        int pcap = cap;
        while(!d.empty() && dcap--){
            mx = max(mx, d.top());
            d.pop();
        }
        while(!p.empty() && pcap--){
            mx = max(mx, p.top());
            p.pop();
        }
        answer += mx * 2;
    } 
    return answer;
}