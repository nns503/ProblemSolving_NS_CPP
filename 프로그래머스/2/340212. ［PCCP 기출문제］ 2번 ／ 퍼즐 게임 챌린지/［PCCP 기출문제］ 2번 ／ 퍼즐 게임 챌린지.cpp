#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &dif, vector<int> &t, long long limit, int p){
    long long sum = 0;
    for(int i=0; i<dif.size(); i++){
        long long level = dif[i];
        long long time = t[i];
        if(p < level){
            sum += (level - p) *  (time + t[i-1]); 
        }
        sum += time;
    }
    if(sum <= limit) return true;
    return false;
}
int solution(vector<int> dif, vector<int> t, long long limit) {
    int answer = 0;
    int st = 1;
    int en = *max_element(dif.begin(), dif.end());
    while(st <= en){
        int mid = (st + en) / 2;
        bool flag = solve(dif, t, limit, mid);
        
        if(flag){
            en = mid-1;
            answer = mid;
        }
        else{
            st = mid+1;
        }
    }
    return answer;
}