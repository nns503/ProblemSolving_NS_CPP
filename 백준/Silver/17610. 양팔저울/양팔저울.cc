#include <bits/stdc++.h>

using namespace std;

void solve(int sum, int index, vector<int> &arr, vector<bool> &vis){
    if(index == arr.size()){
        if(sum > 0){
            vis[sum] = true;
        }
        return;
    }
    
    solve(sum + arr[index], index+1, arr, vis);
    solve(sum - arr[index], index+1, arr, vis);
    solve(sum, index+1, arr, vis);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    vector<int> arr(k);

    int sum = 0;

    for(int i=0; i<k; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    vector<bool> vis(sum+1, false);
    solve(0, 0, arr, vis);

    int answer = 0;
    for(int i=1; i<=sum; i++){
        if(!vis[i]) answer++;
    }

    cout << answer;
    
    return 0;
}