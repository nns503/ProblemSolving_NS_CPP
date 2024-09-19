#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for(auto &cur : arr){
        int a, b;
        cin >> a >> b;
        cur = {b, a};
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    int l = arr[0].B;
    int r = arr[0].B + 1;
    answer = arr[0].A;

    for(int i=1; i<n; i++){
        auto t = arr[i].A;
        auto p = arr[i].B;
        if(p + 1 >= r){
            answer += ((p + 1) - r) * t;
            r = p + 1;

        }
        else if(p <= l){
            answer += (l - p) * t;
            l = p;
        }

    }

    cout << answer;
    return 0;
}