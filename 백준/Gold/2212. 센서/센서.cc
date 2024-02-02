#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> arr;
vector<int> dist;
int answer;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        int a; cin >> a; arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    
    for(int i=1; i<n; i++){
        int num = arr[i] - arr[i-1];
        if(num == 0) continue;
        else dist.push_back(arr[i] - arr[i-1]);
    }
    
    sort(dist.begin(), dist.end());
    
    if(dist.empty()){
        cout << 0;
        return 0;
    }
    
    for(int i=0; i<dist.size() - (k-1); i++){
        answer += dist[i];
    }

    cout << answer;

    return 0;
}