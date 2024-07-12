#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i=1; i<=n; i++){
        arr[i-1] = i;
    }

    do{
        for(auto cur : arr) cout << cur << ' ';
        cout << '\n';
    }while(next_permutation(arr.begin(), arr.end()));

    return 0;
}