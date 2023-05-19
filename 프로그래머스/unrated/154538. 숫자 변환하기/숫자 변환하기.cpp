#include <bits/stdc++.h>

using namespace std;

const int M = 1000000;
int cnt[1000001];
queue<int> q;

int solution(int x, int y, int n) {
    fill(cnt, cnt+M+1, M+1);
    q.push(x);
    cnt[x] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur + n <= M && cnt[cur] + 1 < cnt[cur+n]){
            q.push(cur+n);
            cnt[cur+n] = cnt[cur] + 1;
        }
        
        if(cur * 2 <= M && cnt[cur] + 1 < cnt[cur*2]){
            q.push(cur*2);
            cnt[cur*2] = cnt[cur] + 1;
        }
        
        if(cur * 3 <= M && cnt[cur] + 1 < cnt[cur*3]){
            q.push(cur*3);
            cnt[cur*3] = cnt[cur] + 1;
        }
    }
    return (cnt[y] == M + 1 ? -1 : cnt[y]);
}