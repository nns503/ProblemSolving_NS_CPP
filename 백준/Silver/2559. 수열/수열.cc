#include <bits/stdc++.h>

using namespace std;

int n, k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<int> arr(n);

    for(auto &cur : arr) cin >> cur;

    int sum = 0;

    for(int i=0; i<k; i++){
        sum += arr[i];
    }

    int ans = sum;

    for(int i=k; i<n; i++){
        sum -= arr[i-k];
        sum += arr[i];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}