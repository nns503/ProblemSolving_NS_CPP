#include <bits/stdc++.h>

using namespace std;

map<string, int> target;
map<string, int> m;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0; i<want.size(); i++) target[want[i]] = number[i];
    for(int i=0; i<discount.size(); i++){
        m[discount[i]]++; 
        if(i>=10) m[discount[i-10]]--;
        bool chk = true;
        for(int i=0; i<want.size(); i++){
            if(target[want[i]] != m[want[i]]) chk = false;
        }
        if(chk) answer++;
    }
    
    return answer;
}