#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int st = 0;
    for(int i=0; i<number.size() - k; i++){
        auto mx = number[st];
        int mxId = st;
        for(int j=st; j<=k+i; j++){
            if(mx < number[j]){
                mx = number[j];
                mxId = j;
            }
        }
        answer += mx;
        st = mxId + 1;
    }
    
    return answer;
}