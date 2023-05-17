#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> s) {
    int answer = 0;
    int en = -1;
    for(int i=0; i<s.size(); i++){
        if(en < s[i]){
            en = s[i] + m - 1;
            answer++;
        }
    }
    return answer;
}