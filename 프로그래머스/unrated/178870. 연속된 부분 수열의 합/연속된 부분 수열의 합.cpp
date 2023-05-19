#include <bits/stdc++.h>

using namespace std;

int st = -1;
int en = 0;
int sum = 0;

vector<int> solution(vector<int> seq, int k) {
    vector<int> answer(2);
    answer[1] = 100000000;
    while(en < seq.size()){
        sum += seq[en];
        while(sum > k){
            st++;
            sum -= seq[st];
        }
        if(sum == k){
            if(answer[1] - answer[0] > en - (st+1)){
                answer[1] = en;
                answer[0] = st+1;
            }
        }
        en++;
    }
    return answer;
}