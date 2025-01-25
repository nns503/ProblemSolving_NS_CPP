#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> pred(n);

    for(auto &cur : pred) cin >> cur;
    sort(pred.begin(), pred.end());

    long answer = 0;

    for(int i=1; i<=n; i++){
        answer += abs(pred[i-1] - i);
    }

    cout << answer;

    
    return 0;
}