#include <bits/stdc++.h>

using namespace std;

int play[501];

vector<pair<double, int>> fail;
bool cmp(pair<double, int> p1, pair<double, int> p2){
    if(p1.first == p2.first){
        p1.second < p2.second;
    }
    return p1.first > p2.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double p = stages.size();
    sort(stages.begin(), stages.end());
    
    for(auto a : stages){
        play[a]++;
    }
    
    for(int i=1; i<=N; i++){
        double per;
        if(p == 0) per = 0;
        else per = play[i]/p;
        fail.push_back({per, i});
        p -= play[i];
    }
    
    stable_sort(fail.begin(), fail.end(), cmp);
    
    for(int i=0; i<N; i++){
        answer.push_back(fail[i].second);
    }
    
    return answer;
}
