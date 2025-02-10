#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(4, 0);
    vector<int> twoPattern = {1, 3, 4, 5};
    vector<int> pattern = {3, 1, 2, 4, 5};    
    int one = 1;
    int two = 0;
    int three = 0;
    for(int i=0; i<answers.size(); i++){
        auto cur = answers[i];
        if(cur == one){
            score[1]++;
        }
        one = one % 5 + 1;
        
        if(cur == pattern[three]) score[3]++;
        if(i % 2 == 0){
            if(cur == 2) score[2]++;
        }
        else{
            if(cur == twoPattern[two]){
                score[2]++;
            }
            two = (two + 1) % 4;
            three = (three + 1) % 5;
        }
    }
    
    int maxNum = *max_element(score.begin(), score.end());
    for(int i=1; i<=3; i++){
        if(maxNum == score[i]) answer.push_back(i);
    }
    
    return answer;
}