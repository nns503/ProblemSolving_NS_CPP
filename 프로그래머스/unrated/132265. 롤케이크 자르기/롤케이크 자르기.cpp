#include <bits/stdc++.h>

using namespace std;

int lc[1000001];
int rc[1000001];

int solution(vector<int> topping) {
    int answer = 0;
    set<int> s1, s2;
    for(int i = 0; i < topping.size(); i++){
        s1.insert(topping[i]);
        lc[i] = s1.size();
    }
    for(int i = topping.size()-1; i >= 0; i--){
        s2.insert(topping[i]);
        rc[i] = s2.size();
    }
    
    for(int i = 0; i < topping.size()-1; i++){
        if(lc[i] == rc[i+1]) answer++;
    }
    return answer;
}