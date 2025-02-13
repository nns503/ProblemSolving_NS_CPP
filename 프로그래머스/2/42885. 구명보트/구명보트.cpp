#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    vector<bool> vis(people.size(), false);
    int en = people.size() - 1;
    for(int st=0; st<people.size(); st++){
        if(vis[st]) continue;
        if(st >= en){
            answer++;
            continue;
        }
        while(st < en){
            if(people[st] + people[en] <= limit){
                vis[en] = true;
                en--;
                break;
            }
            en--;
        }
        vis[st] = true;
        answer++;
    }
    
    return answer;
}