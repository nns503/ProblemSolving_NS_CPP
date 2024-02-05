#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, answer;
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int a, st, en;
        cin >> a >> st >> en;
        arr.push_back({st, en});
    }

    sort(arr.begin(), arr.end());

    pq.push(arr[0].Y);
    answer = 1;

    for(int i=1; i<n; i++){
        while(!pq.empty() && pq.top() <= arr[i].X){
            pq.pop();
        }
        pq.push(arr[i].Y);
        answer = max((int)pq.size(), answer);
    }

    cout << answer;

    
    return 0;
}