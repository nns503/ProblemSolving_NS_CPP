/*

*/
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int l, vector<vector<int>> &arr){
    int st = 0;
    int time = 0;
    for(int i=0; i<n; i++){
        int d = arr[i][0];
        int red = arr[i][1];
        int green = arr[i][2];

        time += d - st;
        st = d;
        if(red >= time % (red + green)){
            time += red - (time % (red + green));
        }
    }

    time += l - st;
    return time;    
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<vector<int>> arr(n, vector<int>(3));

    for(auto &cur : arr){
        cin >> cur[0] >> cur[1] >> cur[2];
    }

    cout << solve(n, l, arr);

    return 0;
}

