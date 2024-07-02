#include <bits/stdc++.h>

using namespace std;

int s, m;
int solve(int cnt, int sum, int n, vector<vector<int>> &memo, vector<int> &arr){
    if(cnt >= n) return sum;
    if(memo[cnt][sum] != -2) return memo[cnt][sum];

    int p = sum + arr[cnt];
    int mn = sum - arr[cnt];
    int ans = -1;
    
    if(p <= m) ans = max(ans, solve(cnt+1, p, n, memo, arr));
    if(mn >= 0) ans = max(ans, solve(cnt+1, mn, n, memo, arr));

    return memo[cnt][sum] = ans;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> s >> m;
    vector<int> arr(n);
    vector<vector<int>> memo(n, vector<int>(m+1, -2));

    for(auto &cur : arr){
        cin >> cur;
    }
    cout << solve(0, s, n, memo, arr);
    return 0;
}