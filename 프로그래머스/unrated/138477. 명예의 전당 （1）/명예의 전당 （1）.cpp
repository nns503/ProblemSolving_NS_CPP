#include <bits/stdc++.h>

using namespace std;

vector<int> sc;
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for(int i=0; i<score.size(); i++){
        sc.push_back(score[i]);
        sort(sc.begin(), sc.end(), greater<>());
        if(sc.size() <= k) answer.push_back(sc.back());
        else{
            answer.push_back(sc[k-1]);
        }
    }
    return answer;
}