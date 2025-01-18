#include <bits/stdc++.h>

using namespace std;

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
    int aI, aSum, aSubmit, aTime;
    int bI, bSum, bSubmit, bTime;
    tie(aI, aSum, aSubmit, aTime) = a;
    tie(bI, bSum, bSubmit, bTime) = b;
    if(aSum == bSum){
        if(aSubmit == bSubmit){
            return aTime < bTime;
        }
        return aSubmit < bSubmit;
    }
    return aSum > bSum;

}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        vector<vector<int>> solve(n+1,vector<int>(k+1, 0));
        vector<int> submit(n+1, 0);
        vector<int> time(n+1, 0);

        for(int a=1; a<=m; a++){
            int i, j, s;
            cin >> i >> j >> s;
            solve[i][j] = max(solve[i][j], s);
            submit[i]++;
            time[i] = a;
        }

        vector<tuple<int, int, int, int>> arr;
        for(int i=1; i<=n; i++){
            int sum = 0;
            for(auto cur : solve[i]) sum += cur;
            arr.push_back({i, sum, submit[i], time[i]});
        }

        sort(arr.begin(), arr.end(), cmp);
        for(int i=0; i<arr.size(); i++){
            int index = get<0>(arr[i]);
            if(index == t) cout << i+1 << '\n';
        }
    }

    return 0;
}