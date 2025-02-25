#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;

int getAlpNum(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a' + 1;
    }   
    else{
        return c - 'A' + 27;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    cin >> n;
    vector<pair<int, int>> adj[n];
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            if(str[j] == '0') continue;
            int len = getAlpNum(str[j]);
            adj[i].push_back({len, j});
            adj[j].push_back({len, i});
            sum += len;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> dist(n, false);
    pq.push({0, 0});
    int answer = 0;
    int cnt = 0;
    while(!pq.empty() && cnt < n){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.B]) continue;
        dist[cur.B] = true;
        answer += cur.A;
        cnt++;
        for(auto nxt : adj[cur.B]){
            if(dist[nxt.B]) continue;
            pq.push(nxt);
        }
    }

    if(cnt != n) cout << -1;
    else{

        cout << sum - answer;
    }


    return 0;
}