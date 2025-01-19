#include <bits/stdc++.h>

using namespace std;

int n, h, t;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> t;
    priority_queue<int> pq;
    
    for(int i=0; i<n; i++){
        int a; cin >> a;
        pq.push(a);
    }

    int cnt = 0;
    for(int i=0; i<t; i++){
        auto cur = pq.top(); pq.pop();
        if(cur == 1) break;
        if(cur < h) break;
        cnt++;
        pq.push(cur/2);
    }    

    auto cur = pq.top(); pq.pop();
    if(cur >= h){
        cout << "NO\n" << cur;
    }
    else{
        cout << "YES\n" << cnt;
    }            
    
    return 0;
}