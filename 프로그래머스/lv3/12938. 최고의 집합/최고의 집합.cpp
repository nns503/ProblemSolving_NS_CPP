#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s) return {-1};
    else{
        int t = n;
        while(t--){
            answer.push_back(s/n);
        }
        for(int i=0; i<s%n; i++) answer[i] += 1;
        sort(answer.begin(), answer.end());
        return answer;
    }
}