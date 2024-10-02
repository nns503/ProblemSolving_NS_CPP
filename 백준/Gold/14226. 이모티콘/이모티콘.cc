#include <bits/stdc++.h>
#define T first
#define C second

using namespace std;

bool OOB(int text, int clip){
    return (text < 0 || clip < 0 || text > 2000 || clip > 2000);
}

int solve(int text, vector<vector<int>> &memo){
    queue<pair<int, int>> q;
    memo[1][0] = 0;
    q.push({1, 0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(text == cur.T) return memo[cur.T][cur.C];

        if(!OOB(cur.T, cur.T) && memo[cur.T][cur.T] == -1){
            memo[cur.T][cur.T] = memo[cur.T][cur.C] + 1;
            q.push({cur.T, cur.T});
        }
        if(!OOB(cur.T + cur.C, cur.C) && memo[cur.T + cur.C][cur.C] == -1){
            memo[cur.T + cur.C][cur.C] = memo[cur.T][cur.C] + 1;
            q.push({cur.T + cur.C, cur.C});
        }
        if(!OOB(cur.T - 1, cur.C) && memo[cur.T - 1][cur.C] == -1){
            memo[cur.T - 1][cur.C] = memo[cur.T][cur.C] + 1;
            q.push({cur.T - 1, cur.C});
        }
    }

    return -1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin >> s;
    vector<vector<int>> memo(2001, vector<int>(2001, -1));
    
    cout << solve(s, memo);

    return 0;
}