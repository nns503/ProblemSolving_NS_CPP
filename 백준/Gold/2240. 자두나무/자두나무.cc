#include <bits/stdc++.h>

using namespace std;

int t, w;
int arr[1001];
int dp[1001][31][2];
int answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    
    for(int i=1; i<=t; i++){
        cin >> arr[i];
    }

    if(arr[1] == 1){
        for(int k=0; k<=w; k++) dp[1][k][1]++;
    }
    else{
        for(int k=1; k<=w; k++) dp[1][k][2]++;
    }

    for(int i=2; i<=t; i++){
        dp[i][0][1] = dp[i-1][0][1] + (arr[i] == 1);
        dp[i][0][2] = dp[i-1][0][2] + (arr[i] == 2);
        for(int k=1; k<=w; k++){
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][2]) + (arr[i] == 1);
            dp[i][k][2] = max(dp[i-1][k-1][1], dp[i-1][k][2]) + (arr[i] == 2);
        }
    }
    

    cout << max(dp[t][w][1], dp[t][w][2]);
    return 0;
}