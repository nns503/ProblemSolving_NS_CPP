#include <bits/stdc++.h>

using namespace std;

int m, n, l;
int answer;
vector<int> arr;

int getDist(int x, int a, int b){
    return (abs(x - a) + b);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> l;

    for(int i=0; i<m; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        int a, b, find;
        cin >> a >> b;
        int index = upper_bound(arr.begin(), arr.end(), a) - arr.begin();
        
        if(index != m && abs(arr[index] - a) <= abs(arr[index-1] - a)){
            find = arr[index];
        }    
        else find = arr[index-1];

        int dist = getDist(find, a, b);
        if(dist <= l) answer++;
    }

    cout << answer;
    return 0;
}
