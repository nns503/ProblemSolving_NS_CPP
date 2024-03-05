#include <bits/stdc++.h>

using namespace std;

int n, t, l;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        int mn = -1;
        int mx = -1;
        cin >> l >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            arr.push_back(a);
            mn = max(min(a, l-a), mn);
        }
        sort(arr.begin(), arr.end());

        mx = max(arr[n-1], l - arr[0]);

        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}