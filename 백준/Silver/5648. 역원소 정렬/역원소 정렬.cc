#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> arr(n);
    string str;
    for(auto &cur : arr){
        cin >> str;
        reverse(str.begin(), str.end());
        cur = stoll(str);
    }
    sort(arr.begin(), arr.end());

    for(auto &cur : arr) cout << cur << '\n';
    return 0;
}
