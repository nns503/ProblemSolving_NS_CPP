#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &arr){
    vector<int> memo(n+1, 0);

    for(int i=0; i<n; i++){
        int cost = arr[i];
        int cnt = i+1;
        for(int k=cnt; k<=n; k++){
            memo[k] = max(memo[k], memo[k-cnt] + cost);
        }
    }

    return memo[n];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &cur : arr){
        cin >> cur;
    }

    cout << solve(n, arr);

    return 0;
}