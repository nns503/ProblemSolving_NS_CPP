#include <bits/stdc++.h>

using namespace std;

vector<int> p(100001, 0);

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);    
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return true;
    if(a < b){
        p[a] = b;
    }
    else p[b] = a;
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    for(int i=1; i<=v; i++) p[i] = i;

    vector<tuple<int, int, int>> adj;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({c, a, b});
    }
    sort(adj.begin(), adj.end());

    int answer = 0;
    for(auto cur : adj){
        int c, a, b;
        tie(c, a, b) = cur;
        if(uni(a, b)) continue;
        answer += c;
    }

    cout << answer;
}