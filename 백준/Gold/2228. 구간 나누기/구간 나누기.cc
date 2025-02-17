#include <bits/stdc++.h>

using namespace std;

const int MIN = -3276900;
int n, m;
vector<vector<int>> dp(201, vector<int>(201, -0x3f3f3f3f)); // n index
int arr[101];

int solve(int index, int cnt){
    if(cnt == 0){
        return 0;
    }
    if(index >= n){
        return MIN;
    }
    if(dp[index][cnt] != -0x3f3f3f3f){
        return dp[index][cnt];
    }

    dp[index][cnt] = solve(index+1, cnt);
    int temp = 0;
    for(int i=index; i<n; i++){
        temp += arr[i];
        dp[index][cnt] = max(dp[index][cnt], temp + solve(i+2, cnt-1));
    }

    return dp[index][cnt];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << solve(0, m);
    return 0;
}

/*
4 -1 -1 -1 -1
n = 2
-1 
*/
// 1:40