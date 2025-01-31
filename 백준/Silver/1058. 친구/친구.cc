#include <bits/stdc++.h>

using namespace std;


void solve(string str, vector<bool> &vis){
    for(int i=0; i<str.size(); i++){
        if(vis[i]) continue;
        if(str[i] == 'N') continue;
        vis[i] = true;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> arr(n);    
    vector<int> answer(n, 0);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        string cur = arr[i];
        vector<bool> vis(n, false);
        vis[i] = true;
        for(int j=0; j<cur.size(); j++){
            if(cur[j] == 'N') continue;
            vis[j] = true;
            solve(arr[j], vis);
        }
        for(int j=0; j<cur.size(); j++){
            if(i == j) continue;
            if(!vis[j]) continue;
            answer[i]++;
        }
    }

    cout << *max_element(answer.begin(), answer.end());
    return 0;
}