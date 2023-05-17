#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

stack<pair<int, int>> s; // w, index

vector<int> solution(vector<int> n) {
    vector<int> answer;
    answer.resize(n.size(), -1);
    s.push({1000001, -1});
    for(int i=0; i<n.size(); i++){
        while(s.top().X < n[i]){
            answer[s.top().Y] = n[i];
            s.pop();
        }        
        s.push({n[i], i});
    }
    return answer;
}