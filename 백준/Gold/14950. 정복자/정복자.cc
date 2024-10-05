#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

vector<int> p(10001, 0);

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]); 
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return true;

    if(p[u] < p[v]){
        p[u] = v;
    }
    else p[v] = u;

    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<tuple<int, int, int>> road;
    for(int i=1; i<=n; i++) p[i] = i;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        road.push_back({c, a, b});
    }

    sort(road.begin(), road.end());

    int answer = 0;
    int sumT = 0;
    
    for(auto cur : road){
        int a, b, c;
        tie(c, a, b) = cur;
        if(uni(a, b)) continue;
        answer += c + sumT;
        sumT += t;
    }

    cout << answer;
    return 0;
}