#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> hp(3);
    vector<int> arr = {0, 1, 2};
    for(int i=0; i<n; i++) cin >> hp[i];
    for(int i=n; i<3; i++) hp[i] = 0;
    
    vector<vector<vector<int>>> vis(61, vector<vector<int>>(61, vector<int>(61, -1)));
    vis[hp[0]][hp[1]][hp[2]] = 0;
    queue<tuple<int, int, int>> q;
    q.push({hp[0], hp[1], hp[2]});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        vector<int> h(3);
        tie(h[0], h[1], h[2]) = cur;
        int dist = vis[h[0]][h[1]][h[2]];
        if(h[0] == 0 && h[1] == 0 && h[2] == 0){
            cout << vis[h[0]][h[1]][h[2]];
            return 0;
        }
        do{
            int nh1 = h[arr[0]] - 9;
            int nh2 = h[arr[1]] - 3;
            int nh3 = h[arr[2]] - 1;
            if(nh1 < 0) nh1 = 0;
            if(nh2 < 0) nh2 = 0;
            if(nh3 < 0) nh3 = 0;
            if(vis[nh1][nh2][nh3] != -1) continue;
            vis[nh1][nh2][nh3] = dist + 1; 
            q.push({nh1, nh2, nh3});
        }while(next_permutation(arr.begin(), arr.end()));
    }
}
