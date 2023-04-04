#include <bits/stdc++.h>

int num[2];
char target;
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        if(num[0] == 0){
            num[0]++;
            target = s[i];
        }
        else if(target == s[i]){
            num[0]++;
        }
        else{
            num[1]++;
        }
        if(num[0] == num[1] || i == s.size() - 1){
            answer++;
            num[0] = 0; num[1] = 0;
        }
    }
    return answer;
}