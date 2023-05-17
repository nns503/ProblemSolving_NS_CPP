#include <bits/stdc++.h>
using namespace std;

int dp[100001][5];

int solution(vector<vector<int>> land)
{
    for(int i=0; i<4; i++) dp[0][i] = land[0][i];
    
    for(int y=1; y<land.size(); y++){
        for(int x=0; x<4; x++){
            int mx = 0;
            for(int prev = 0; prev<4; prev++){
                if(x == prev) continue;
                mx = max(mx, dp[y-1][prev]);
            }
            dp[y][x] = land[y][x] + mx;
        }
    }
    return *max_element(dp[land.size()-1], dp[land.size()-1]+4);
}