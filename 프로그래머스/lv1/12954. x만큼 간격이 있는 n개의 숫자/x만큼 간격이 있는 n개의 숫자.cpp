#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int a = x;
    while(n--){
        answer.push_back(x);
        x += a;
    }
    return answer;
}