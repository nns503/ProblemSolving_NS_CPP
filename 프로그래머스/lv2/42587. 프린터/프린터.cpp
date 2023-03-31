#include <bits/stdc++.h>

using namespace std;

vector<int> v;
queue<pair<int, int>> q;
int cnt = 0;
int num[101];

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i], i});
        v.push_back(priorities[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.first == v[cnt]){
            num[cur.second] = cnt+1;
            cnt++;
        }
        else{
            q.push(cur);
        }
    }
    return num[location];
}