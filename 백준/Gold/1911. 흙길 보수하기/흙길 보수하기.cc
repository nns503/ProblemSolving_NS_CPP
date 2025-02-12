#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n, l;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    int p = 0;
    for(auto cur : arr){
        int st = cur.A; 
        int en = cur.B; 
        if(p >= en) continue;
        if(p > st) st = p;
        int cnt = (en - st + l - 1) / l;
        answer += cnt;
        p = max(p, st + (cnt * l));
    }

    cout << answer;
    return 0;
}