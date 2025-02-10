#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 1;
    int h = 1;
    for(auto cur : sizes){
        int caseWH = max(w, cur[0]) * max(h, cur[1]);
        int caseHW = max(w, cur[1]) * max(h, cur[0]);
        if(caseWH < caseHW){
            w = max(w, cur[0]);
            h = max(h, cur[1]);
        }
        else{
            w = max(w, cur[1]);
            h = max(h, cur[0]);
        }
    }
    return w*h;
}