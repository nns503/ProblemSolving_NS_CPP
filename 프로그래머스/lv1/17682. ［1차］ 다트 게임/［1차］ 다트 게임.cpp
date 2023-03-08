#include <bits/stdc++.h>

using namespace std;

int num[4];
int cnt = 0;

int solution(string dartResult) {
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            cnt++;
            if(dartResult[i] == '1'&&dartResult[i+1] == '0'){
                num[cnt] += 10;
                i++;
                continue;
            }
            num[cnt] = dartResult[i] - '0';
        }
        else if(dartResult[i] == 'D') num[cnt] *= num[cnt];
        else if(dartResult[i] == 'T') num[cnt] *= num[cnt] * num[cnt];
        else if(dartResult[i] == '*'){
            num[cnt-1] *= 2;
            num[cnt] *= 2;
        }
        else if(dartResult[i] == '#'){
            num[cnt] *= -1;
        }
    }
    return num[1] + num[2] + num[3];
}