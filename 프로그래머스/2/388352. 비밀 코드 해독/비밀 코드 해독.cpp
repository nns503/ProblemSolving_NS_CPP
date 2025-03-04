#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

void setArr(int st, int k, vector<int> &numbers){
    if(numbers.size() == 5){
        arr.push_back(numbers);
        return ;
    }
    for(int i=st; i<=k; i++){
        numbers.push_back(i);
        setArr(i+1, k, numbers);
        numbers.pop_back();
    }
}

int getSameCount(vector<int> &a, vector<int> &b){
    set<int> sameSet;
    for(int i=0; i<5; i++){
        sameSet.insert(a[i]);
        sameSet.insert(b[i]);
    }
    
    return 10 - sameSet.size();
}

bool solve(vector<int> cur, vector<vector<int>> &q, vector<int> &ans){
    for(int i=0; i<ans.size(); i++){
        int answer = ans[i];
        vector<int> que = q[i];
        if(getSameCount(cur, que) != answer) return false;
    }
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> numbers;
    setArr(1, n, numbers);
    
    for(auto cur : arr){
        if(solve(cur, q, ans)) answer++;
    }
    
    return answer;
}