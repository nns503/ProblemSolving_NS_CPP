#include <bits/stdc++.h>

using namespace std;

queue<string> Q;

string toL(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    bool hit = false;
    string tempcity;
    for(auto city : cities){
        city = toL(city);
        if(cacheSize != 0){
            for(int i=0; i<Q.size(); i++){
                if(Q.front() == city){
                    hit = true;
                    tempcity = city;
                    Q.pop();
                    i--;
                }
                else{
                    string temp = Q.front();
                    Q.pop();
                    Q.push(temp);
                }
            }
            if(hit){
                Q.push(tempcity);
            }
            else{
                if(Q.size() == cacheSize) Q.pop();
                Q.push(city);                
            }
        }
        hit ? answer++ : answer += 5;
        hit = false;
    }
    return answer;
}