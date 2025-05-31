#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> q;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        q.push(a);
    }


    while(m--){
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        q.push(a+b);
        q.push(a+b);
    }

    long long answer = 0;
    while(!q.empty()){
        answer += q.top(); q.pop();
    }

    cout << answer;
}