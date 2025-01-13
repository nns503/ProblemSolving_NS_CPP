#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }

    int index;

    for(int i=0; i<n; i++){
        if(arr[i] == n){
            index = i;
            break;
        }
    }

    int cnt = 1;
    for(int i=index-1; i>=0; i--){
        if(arr[i] == n - cnt){
            cnt++;
        }
    }
    
    cout << n - cnt;
}