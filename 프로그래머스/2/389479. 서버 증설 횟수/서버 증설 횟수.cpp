#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int t=0; t<players.size(); t++){
        while(!q.empty()){
            auto a = q.top();
            if(a + k <= t){
                q.pop();
                continue;
            }
            break;
        }
        
        int player = players[t];
        int server = q.size();
        int w = player - server * m;
        while(w >= m){
            w -= m;
            answer++;
            q.push(t);
        }
    }
    return answer;
}