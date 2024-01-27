#include <bits/stdc++.h>
#define X frist
#define Y second

using namespace std;

int T, n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while(T--){
        int answer = 0;
        int mx = 1000000;
        vector<pair<int, int>> arr;
        cin >> n;

        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            arr.push_back({a, b});
        }

        sort(arr.begin(), arr.end());

        for(pair<int, int> cur : arr){
            if(cur.second >= mx) continue;
            answer++;
            mx = cur.second;
        }

        cout << answer << '\n';
    }
    return 0;
}