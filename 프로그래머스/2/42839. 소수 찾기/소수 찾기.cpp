#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 9999999;

vector<int> getDecimal(){
    vector<bool> chk(MAX_VALUE + 1, false);
    vector<int> decimal;
    for(int i=2; i<=MAX_VALUE; i++){
        if(!chk[i]){
            decimal.push_back(i);
            for(int j=i+i; j<=MAX_VALUE; j+=i){
                chk[j] = true;
            }
        }
    }
    
    return decimal;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> decimal = getDecimal();
    vector<int> maxCount(10, 0);
    for(auto cur : numbers){
        maxCount[cur - '0']++;
    }
    
    for(auto cur : decimal){
        
        vector<int> count(10, 0);
        while(cur > 0){
            int n = cur % 10;
            cur /= 10;
            count[n]++;
        }
        bool flag = true;
        for(int i=0; i<=9; i++){
            if(count[i] > maxCount[i]){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}