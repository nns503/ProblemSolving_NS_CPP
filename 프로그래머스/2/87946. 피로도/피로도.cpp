#include <bits/stdc++.h>

using namespace std;

int answer = -1;

void solve(int k, vector<bool> &vis, vector<vector<int>> &dungeons, int clear){
    if(answer < clear) answer = clear;
    for(int i=0; i<dungeons.size(); i++){
        if(vis[i]) continue;
        if(dungeons[i][0] > k) continue;
        vis[i] = true;
        solve(k - dungeons[i][1], vis, dungeons, clear+1);
        vis[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> vis(dungeons.size(), false);
    solve(k, vis, dungeons, 0); 
    
    return answer;
}