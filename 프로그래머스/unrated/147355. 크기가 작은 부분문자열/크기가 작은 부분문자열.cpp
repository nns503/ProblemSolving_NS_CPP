#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len = p.size();
    for(int i=0; i<=t.size()-len; i++){
        string a = t.substr(i, len);
        if(a <= p) answer++;
    }
    return answer;
}