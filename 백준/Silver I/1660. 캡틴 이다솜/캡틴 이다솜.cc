#include <bits/stdc++.h>

using namespace std;

const int MAX = 300000;
int n;
int dp[300001];
vector<int> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int d = 1;
    int s = 2;

    while(sum + d <= MAX){
        sum += d;
        d += s;
        s++;
        arr.push_back(sum);
    }


    cin >> n;

    fill(dp, dp+300001, MAX);
    dp[0] = 0;

    for(int i=0; i<arr.size(); i++){
        int cur = arr[i];
        for(int j=cur; j<=MAX; j++){
            dp[j] = min(dp[j], dp[j-cur] + 1);
        }
    }
    
    cout << dp[n];
    
    return 0;
}