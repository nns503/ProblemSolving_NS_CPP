#include <bits/stdc++.h>

using namespace std;
queue<int> p;
queue<int> s;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0; i<speeds.size(); i++){
        p.push(progresses[i]);
        s.push(speeds[i]);
    }
    while(!p.empty()){
        int t = p.size();
        while(t--){
            int np = p.front(); p.pop();
            int ns = s.front(); s.pop();
            np += ns;
            p.push(np);
            s.push(ns);
        }
        int cnt = 0;
        while(!p.empty() && p.front() >= 100){
            p.pop();
            s.pop();
            cnt++;
        }
        if(cnt > 0) answer.push_back(cnt);
    }
    return answer;
}