#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &arr){
    vector<int> sum(n+1, 0);
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + arr[i];
    }

    int answer = 0;
    
    for(int i=2; i<n; i++){
        answer = max(answer, (sum[i] - sum[1]) + (sum[n-1] - sum[i-1]));
    }
    
    for(int i=2; i<n; i++){
        answer = max(answer, (sum[n] - sum[1]) - arr[i] + (sum[n] - sum[i]));
    }

    for(int i=2; i<n; i++){
        answer = max(answer, (sum[n-1] - arr[i]) + sum[i-1]);
    }
    
    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    cout << solve(n, arr);

    return 0;
}