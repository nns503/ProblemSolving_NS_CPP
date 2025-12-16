#include <bits/stdc++.h>

using namespace std;

int solve(int n){
    vector<int> memo(100001, -1);
    memo[2] = 1;
    memo[4] = 2;
    memo[5] = 1;
    memo[6] = 3;
    memo[7] = 2;
    memo[8] = 4;

    for(int i=9; i<=n; i++){
        memo[i] = min(memo[i - 2] + 1, memo[i - 5] + 1);
        if(memo[i] == 0) memo[i] = -1;
    }

    return memo[n];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}