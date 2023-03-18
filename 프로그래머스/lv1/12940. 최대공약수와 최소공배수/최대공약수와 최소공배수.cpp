#include <bits/stdc++.h>

using namespace std;
int GCD(int n, int m){
    return n % m == 0 ? m : GCD(m, n%m);
}

int LCM(int n, int m){
    return n * m / GCD(n, m); 
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    if(n<m){
        answer.push_back(GCD(n, m));
        answer.push_back(LCM(n, m));
    }
    else{
        answer.push_back(GCD(m, n));
        answer.push_back(LCM(m, n));
    }
    return answer;
}