#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int t = 0;
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
        > task;
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
        > wait;
    for(int i=0; i<jobs.size(); i++){
        task.push({jobs[i][0], jobs[i][1],i});
    }
    
    while(!task.empty() || !wait.empty()){
        while(!task.empty() && get<0>(task.top()) <= t){
            int a, b, c;
            tie(a, b, c) = task.top(); task.pop();
            wait.push({b, a, c});
        }
        if(wait.empty()){
            t++;
        }
        else{
            int a, b, c;
            tie(a, b, c) = wait.top(); wait.pop();
            t += a; 
            answer += (t - b);
        }
    } 
    
    return answer / jobs.size();
}