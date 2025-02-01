#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 0;
vector<int> arr;

int getEnergy(int index, vector<bool> &vis){
    int sum = 1;
    for(int i=index-1; i>=0; i--){
        if(vis[i]) continue;
        sum *= arr[i];
        break;
    }
    for(int i=index+1; i<n; i++){
        if(vis[i]) continue;
        sum *= arr[i];
        break;
    }
    
    return sum;
}

void solve(int size, int sum, vector<bool> &vis){
    if(size == 2){
        answer = max(answer, sum);
        return ;
    }

    for(int i=1; i<vis.size()-1; i++){
        if(vis[i]) continue;
        vis[i] = true;
        int energy = getEnergy(i, vis);
        solve(size-1, sum+energy, vis);
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    vector<bool> vis(n, false);
    solve(n, 0, vis);

    cout << answer;
    return 0;
}