#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<double> arr(n);
    for(auto &cur : arr) cin >> cur;

    sort(arr.begin(), arr.end(), greater<double>());
    double answer = arr[0];
    for(int i=1; i<n; i++){
        auto cur = arr[i];
        auto d = cur / 2;
        answer += d;
    }

    cout << answer;

    return 0;
}