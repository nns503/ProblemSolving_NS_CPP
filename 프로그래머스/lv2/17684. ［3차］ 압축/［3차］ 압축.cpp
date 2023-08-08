#include <bits/stdc++.h>

using namespace std;
map<string, int> m;
bool chk = false;
int cnt = 27;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=1; i<=26; i++){ 
        char c = 'A';
        c += i-1;
        string str = string(1, c);
        m[str] = i;
    }
    
    for(int i=0; i<msg.size();){
        string temp;
        temp.push_back(msg[i]); i++;
        while(m[temp + msg[i]] != 0 && i<msg.size()){
            temp.push_back(msg[i]);
            i++;
        }
        
        answer.push_back(m[temp]);
        temp.push_back(msg[i]);
        m[temp] = cnt;
        cnt++;
    }
    
    return answer;
}