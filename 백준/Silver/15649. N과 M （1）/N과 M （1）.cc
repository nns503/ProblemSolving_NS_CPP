#include <bits/stdc++.h>

using namespace std;

void func(vector<int> &arr, vector<bool> &vis, int cnt, int n, int m){
    if(cnt == m){
        for(auto cur : arr){
            cout << cur << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        arr[cnt] = i;
        vis[i] = true;
        func(arr, vis, cnt+1, n, m);
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr(m);
    vector<bool> vis(m, false);
    func(arr, vis, 0, n, m);
    return 0;
}