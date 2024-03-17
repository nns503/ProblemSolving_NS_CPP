#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> q1, vector<int> q2) {
    int answer = 0;
    int index1 = 0; int index2 = 0;
    long long sum1 = 0; long long sum2 = 0;
    
    for(int i=0; i<q1.size(); i++){
        sum1 += q1[i];
    }
    for(int i=0; i<q2.size(); i++){
        sum2 += q2[i];
    }
    
    long long mn = sum1 - sum2;
    int mxsize = q1.size() + q2.size();
    
    while(mn != 0 && index1 < mxsize && index2 < mxsize){
        if(mn > 0){
            mn -= (2*q1[index1]);
            q2.push_back(q1[index1]);
            index1++;
        }
        else{
            mn += (2*q2[index2]);
            q1.push_back(q2[index2]);
            index2++;
        }
        answer++;
    }
    
    if(mn != 0) answer = -1;
    return answer;
}