#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for(auto a : d){
        budget -= a;
        if(budget >= 0) answer++;
        if(budget <= 0) break;
    }
    return answer;
}