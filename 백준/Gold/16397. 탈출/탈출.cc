#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, t, g;
int dp[100001];
queue<int> q;

bool OOB(int num){
    return (num < 0 || num > 99999);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t >> g;
    
    fill(dp, dp+100001, INF);

    dp[n] = 0;

    q.push(n);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(dp[cur] == t) continue;

        if(!OOB(cur + 1) && dp[cur+1] == INF){
            dp[cur+1] = dp[cur] + 1;
            q.push(cur+1);
        }

        if(cur == 0) continue;
        if(OOB(cur*2)) continue;

        int temp = cur * 2;
        string s = to_string(temp);
        temp -= pow(10, s.size()-1);
        
        if(dp[temp] == INF){
            dp[temp] = dp[cur] + 1;
            q.push(temp);
        }
    }

    if(dp[g] == INF) cout << "ANG";
    else cout << dp[g];

    return 0;
}

