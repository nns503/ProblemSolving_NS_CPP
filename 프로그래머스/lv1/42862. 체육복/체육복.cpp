#include <bits/stdc++.h>

using namespace std;

int stu[33];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    fill(stu+1, stu+n+1, 1);
    for(auto a : lost) stu[a]--;
    for(auto a : reserve) stu[a]++;
    for(int i=1; i<=n; i++){
        if(stu[i] == 0){
            if(stu[i-1] == 2){
                stu[i-1]--;
                stu[i]++;
                continue;
            }
            else if(stu[i+1] == 2){
                stu[i+1]--;
                stu[i]++;
                continue;
            }
        }
    }
    for(auto a : stu) if(a>=1) answer++; 
    
    return answer;
}