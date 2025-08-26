#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> &arr){
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(auto cur : arr){
        pq.push(cur);
    }

    long long answer = 0;

    while(pq.size() >= 2){
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        pq.push(a+b);
        answer += a+b;
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while(T--){
        int k;
        cin >> k;
        vector<int> arr(k);
        for(auto &cur : arr){
            cin >> cur;
        }

        cout << solve(arr) << '\n';
    }
    return 0;
}