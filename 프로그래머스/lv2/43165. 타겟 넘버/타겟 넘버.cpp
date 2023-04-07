#include <bits/stdc++.h>

using namespace std;

vector<int> n;
int answer, len, tg;

void DFS(int cur, int cnt){
    if(cnt == len){
        if(cur == tg) answer++;
        return ;
    }
    DFS(cur+n[cnt], cnt+1);
    DFS(cur-n[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {
    n = numbers;
    len = numbers.size();
    tg = target;
    DFS(0, 0);
    return answer;
}