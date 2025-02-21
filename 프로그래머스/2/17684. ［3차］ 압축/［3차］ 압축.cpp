#include <bits/stdc++.h>

using namespace std;

int lastIndex = 27;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    string alp = "A"; 
    for(int i=1; i<=26; i++){
        alp = 'A' + i - 1;
        m[alp] = i;
    }
    for(int st=0; st<msg.size();){
        int prv = 0;
        int a = 0;
        for(int i=1; i<=msg.size() - st; i++){
            string cur = msg.substr(st, i);
            if(m.find(cur) == m.end()){
                m[cur] = lastIndex++;
                break;
            }
            else{
                prv = m[cur];
                a++;
            }
        }
        st += a;
        answer.push_back(prv);
    }
    return answer;
}