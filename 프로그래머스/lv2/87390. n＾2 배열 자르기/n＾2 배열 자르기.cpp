#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=(left+n)/n; i<=(right+n)/n; i++){
        for(long long j=1; j<=n; j++){
                if(i==(left+n)/n && j <= left % n) continue;
                if(i==(right+n)/n && j > ((right) % n) + 1) continue;
                else{
                    if(j < i) answer.push_back(i);
                    else answer.push_back(j);
                }
            }
        }
        
    return answer;
}