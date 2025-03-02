#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> p;
    map<string, int> score;
    for(auto cur : gifts){
        p[cur]++;
        int k = 0;
        for(int i=0; i<cur.size(); i++){
            if(cur[i] == ' '){
                k = i;
                score[cur.substr(0, k)]++;
                score[cur.substr(k+1)]--;
                break;
            }
        }
    }
    
    map<string, int> ans;
    
    for(int i=0; i<friends.size(); i++){
        string cur = friends[i];
        for(int j=i+1; j<friends.size(); j++){
            string nxt = friends[j];
            string str1 = cur + " " + nxt;
            string str2 = nxt + " " + cur;
            if(p[str1] > p[str2]){
                ans[cur]++;
            }
            else if(p[str1] < p[str2]){
                ans[nxt]++;
            }
            else{
                if(score[cur] < score[nxt]){
                    ans[nxt]++;
                }
                else if(score[cur] > score[nxt]){
                    ans[cur]++;
                }
            }
        }
    }
    
    for(auto cur : ans){
        answer = max(answer, cur.second);
    }
    
    return answer;
}