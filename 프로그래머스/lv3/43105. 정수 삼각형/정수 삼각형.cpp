#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dp) {
    int answer = 0;
    for(int y=1; y<dp.size(); y++){
        for(int x=0; x<=y; x++){
            if(x == 0) dp[y][x] += dp[y-1][x];
            else if(x == y) dp[y][x] += dp[y-1][x-1];
            else dp[y][x] += max(dp[y-1][x-1], dp[y-1][x]); 
        }
    }
    
    return *max_element(dp[dp.size()-1].begin(), dp[dp.size()-1].begin() + dp.size());
}