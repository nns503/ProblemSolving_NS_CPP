#include <bits/stdc++.h>

using namespace std;

int calculateAlp(string name){
    int sum = 0;
    for(auto cur : name){
        int case1 = cur - 'A';
        int case2 = 'Z' - cur + 1;
        sum += min(case1, case2);
    }
    
    return sum;
}

int solve(string name, int p, int cnt, int sum){
    int temp = 0x3f3f3f3f;
    if(cnt == 0){
        return sum;
    }
    int plusPoint = 1;
    int minusPoint = 1;
    while(name[(p + plusPoint) % name.size()] == 'A'){
        plusPoint++;
    }
    while(name[(p - minusPoint + name.size()) % name.size()] == 'A'){
        minusPoint++;
    }
    char c = name[(p + plusPoint) % name.size()]; 
    name[(p + plusPoint) % name.size()] = 'A';
    temp = min(temp, solve(name, (p + plusPoint) % name.size(), cnt-1, sum + plusPoint));
    name[(p + plusPoint) % name.size()] = c;
    
    c = name[(p - minusPoint + name.size()) % name.size()]; 
    name[(p - minusPoint + name.size()) % name.size()] = 'A';
    temp = min(temp, solve(name, (p - minusPoint + name.size()) % name.size(), cnt-1, sum + minusPoint));
    name[(p - minusPoint + name.size()) % name.size()] = c;
    
    return temp;
}

int calculateMove(string name){
    int cnt = 0;
    name[0] = 'A';
    for(auto cur : name){
        if(cur != 'A') cnt++;
    }
    
    return solve(name, 0, cnt, 0);
}

int solution(string name) {
    int answer = 0;
    answer += calculateAlp(name);
    answer += calculateMove(name);
    return answer;
}