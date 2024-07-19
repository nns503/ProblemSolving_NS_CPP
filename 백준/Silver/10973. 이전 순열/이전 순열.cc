#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;

    for(int i=n-1; i>0; i--){
        int cur = arr[i];
        int nxt = arr[i-1];
        
        if(cur > nxt) continue;
        sort(arr.begin() + i, arr.end());
        int index = lower_bound(arr.begin() + i, arr.end(), nxt) - arr.begin() - 1;
        swap(arr[i-1], arr[index]);
        sort(arr.begin() + i, arr.end(), greater<int>());
        
        for(auto ans : arr) cout << ans << ' ';
        return 0;
    }
    cout << -1;

    return 0;
}