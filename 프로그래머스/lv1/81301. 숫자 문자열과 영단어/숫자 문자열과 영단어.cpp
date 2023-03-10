#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            answer *=10;
            answer += (s[i] - '0');
        }
        else if(s[i] == 'z'){
            answer *=10;
            i += 3;
        }
        else if(s[i] == 'o'){
            answer *=10;
            answer += 1;
            i += 2;
        }
        else if(s[i] == 't'){
            answer *= 10;
            if(s[i+1] == 'w'){
                answer += 2;
                i += 2;
            }
            else{
                answer += 3;
                i += 4;
            }
        }
        else if(s[i] == 'f'){
            answer *= 10;
            if(s[i+1] == 'o'){
                answer += 4;
            }
            else{
                answer += 5;
            }
            i += 3;
        }
        else if(s[i] == 's'){
            answer *= 10;
            if(s[i+1] == 'i'){
                answer += 6;
                i += 2;
            }
            else{
                answer += 7;
                i += 4;
            }
        }
        else if(s[i] == 'e'){
            answer *= 10;
            answer += 8;
            i += 4;
        }
        else if(s[i] == 'n'){
            answer *=10;
            answer += 9;
            i += 3;
        }
    }
    return answer;
}