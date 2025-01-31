#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.A == b.A){
        return a.B < b.B;
    }
    return a.A > b.A;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genresListening;
    for(int i=0; i<genres.size(); i++){
        string str = genres[i];
        genresListening[str] += plays[i];
    }
    
    priority_queue<pair<int, string>> pq;
    for(auto cur : genresListening){
        pq.push({cur.B, cur.A});
    }
    
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        vector<pair<int, int>> temp;
        for(int i=0; i<genres.size(); i++){
            if(cur.B == genres[i]){
                temp.push_back({plays[i], i});
            }
        }
        
        sort(temp.begin(), temp.end(), cmp);
        for(int i=0; i<temp.size(); i++){
            answer.push_back(temp[i].B);
            if(i == 1) break;
        }
    }
    return answer;
}