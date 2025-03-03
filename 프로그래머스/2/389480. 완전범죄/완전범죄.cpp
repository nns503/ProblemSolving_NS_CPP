#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
map<pair<int, int>, int> memo;
int maxA;
int maxB;

int solve(int index, int a, int b){
    if(maxA <= a) return 0x3f3f3f3f;
    if(maxB <= b) return 0x3f3f3f3f;
    if(index == arr.size()){
        return a;
    }
    if(memo.find({a, b}) != memo.end()){
        if(memo[{a, b}] >= index) return 0x3f3f3f3f;
    }
    memo[{a, b}] = index;
    
    int answer = 0x3f3f3f3f;
    answer = min(answer, solve(index+1, a + arr[index][0], b));
    answer = min(answer, solve(index+1, a, b + arr[index][1]));
    
    return answer;
}

int solution(vector<vector<int>> info, int n, int m) {
    arr = info;
    maxA = n;
    maxB = m;
    int answer = solve(0, 0, 0);
    if(answer == 0x3f3f3f3f) answer = -1;
    return answer;
}