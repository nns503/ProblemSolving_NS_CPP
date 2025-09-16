#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> m;
    for(auto cur : stages){
        m[cur]++;
    }
    
    vector<pair<double, int>> arr;
    int count = stages.size();
    for(int i=1; i<=N; i++){
        if(count == 0){
            arr.push_back({0, i});
            continue;
        }
        double d = (double) m[i] / count;
        arr.push_back({d, i});
        count -= m[i];   
    }
    sort(arr.begin(), arr.end(), cmp);
    
    for(auto cur : arr){
        answer.push_back(cur.second);
    }
    return answer;
}