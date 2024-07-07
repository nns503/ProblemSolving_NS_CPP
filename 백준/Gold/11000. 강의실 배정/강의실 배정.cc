#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pair<int, int>> arr(n);
    
    int s, t;
    for(int i=0; i<n; i++){
        cin >> s >> t;
        arr[i] = {s, t};
    }

    sort(arr.begin(), arr.end());

    int ans = 0;

    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<n; i++){
        auto cur = arr[i];
        while(!q.empty() && q.top() <= cur.A){ 
            q.pop();                
        }
        q.push(cur.B);
        ans = max(ans, (int)q.size());
    }

    cout << ans;
    return 0;
}