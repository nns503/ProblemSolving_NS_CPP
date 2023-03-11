#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    deque<int> dq;
    dq.push_back(arr[0]);
    for(auto a : arr){
        if(dq.back() != a) dq.push_back(a);
    }
    while(!dq.empty()){
        answer.push_back(dq.front());
        dq.pop_front();
    }
    
    return answer;
}