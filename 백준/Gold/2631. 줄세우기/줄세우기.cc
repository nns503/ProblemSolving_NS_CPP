#include <bits/stdc++.h>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;
    vector<int> len;
    len.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(len.back() < arr[i]){
            len.push_back(arr[i]);
        }
        else{
            len[lower_bound(len.begin(), len.end(), arr[i]) - len.begin()] = arr[i];
        }
    }

    cout << n - len.size();
}

// 2025-02-16 3:38