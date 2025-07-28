/*
이 문제는 문제를 다 읽으면 그냥 백트래킹이 생각이 납니다... ㅜㅜ
백트래킹 문제는 결국 모든 순열(조합도 되던가)을 효율적으로 실행하는 문제이고 이 문제는 운동 키트의 순열 중 되는 것을 찾기 때문임
순열을 백트래킹으로 하는 이유는 1 2 3 에서 처음부터 1 3 2 를 다시 하는 것 보다 1 2 3 에서 (2, 3) 만 바꾸는 것이 더 빠르기 때문임.
*/
#include <bits/stdc++.h>

using namespace std;

int n, k;
int answer = 0;

void dfs(int cnt, int mus, vector<bool> &vis, vector<int> &arr){
    if(cnt == n){
        if(mus < 500) return;
        answer++;
        return ;
    }

    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        if(mus+arr[i]-k < 500) continue;
        vis[i] = true;
        dfs(cnt+1, mus+arr[i]-k, vis, arr);
        vis[i] = false;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<int> arr(n);
    for(auto &cur : arr){
        cin >> cur;
    }
    vector<bool> vis(n, false);
    dfs(0, 500, vis, arr);

    cout << answer;

    return 0;
}