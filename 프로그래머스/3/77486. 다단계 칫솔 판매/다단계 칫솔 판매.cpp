#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
int p[10001];
int money[10001];
queue<int> q;

vector<int> solution(vector<string> enroll, vector<string> referral, 
                     vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0; i<enroll.size(); i++){
        m[enroll[i]] = i;
        string par = referral[i];
        if(par == "-") p[i] = i;
        else{
            p[i] = m[par];
        }
    }
    
    for(int i=0; i<seller.size(); i++){
        int cur = m[seller[i]];
        int par = p[cur];
        int temp = amount[i] * 100;
        while(temp > 0){
            int mn = temp / 10;
            if(cur == par){
                money[cur] += (temp - mn);
                break;
            }
            money[cur] += (temp - mn);
            temp /= 10;
            cur = par;
            par = p[cur];
        }
        
    }
    
    for(int i=0; i<enroll.size(); i++){
        answer.push_back(money[i]);
    }
    
    return answer;
}