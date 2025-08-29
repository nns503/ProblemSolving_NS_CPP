#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &arr){
    sort(arr.begin(), arr.end());

    int answer = 0;
    answer = max(arr[1] - arr[0], answer);
    answer = max(arr[n-1] - arr[n-2], answer);
    for(int i=0; i<n-2; i++){
        answer = max(arr[i+2] - arr[i], answer);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &cur : arr) cin >> cur;

        cout << solve(n, arr) << '\n';
    }
    
    return 0;
}