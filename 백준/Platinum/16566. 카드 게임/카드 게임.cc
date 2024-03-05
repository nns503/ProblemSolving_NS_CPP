#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> arr;
bool vis[4000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i=0; i<m; i++){
        int a; cin >> a; arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    while(k--){
        int a; cin >> a;
        int i = upper_bound(arr.begin(), arr.end(), a) - arr.begin();
        while(vis[i]){
            i++;
        }
        cout << arr[i] << '\n';
        vis[i] = true;
    }
    
    return 0;
}