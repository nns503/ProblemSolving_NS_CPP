#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, l;
    int ans = 0;
    cin >> n >> w >> l;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;

    int st = 0, en = 0;
    int m = 0;
    int t = 0;
    queue<int> q;
    while(st != n){
        t++;
        if(!q.empty() && t - q.front() == w){
            q.pop();
            m -= arr[st];
            st++;
        }
        if(en < n && m + arr[en] <= l){
            q.push(t);
            m += arr[en];
            en++;
        }
    }

    cout << t;

    return 0;
}