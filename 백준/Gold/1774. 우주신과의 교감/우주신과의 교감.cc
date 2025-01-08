#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

const int INF = 0x3f3f3f3f;
int p[1001];

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(a > b) swap(a, b);
    p[b] = a;
    return true;
}

double calculateLen(pair<int, int> p1, pair<int, int> p2){
    return sqrt(pow(p1.Y - p2.Y, 2) + pow(p1.X - p2.X, 2));
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> point(n+1);
    
    for(int i=1; i<=n; i++){
        p[i] = i;
    }

    for(int i=1; i<=n; i++){
        int y, x;
        cin >> y >> x;
        point[i] = {y, x};
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            pq.push({calculateLen(point[i], point[j]), i, j});
        }
    }

    double answer = 0;
    while(!pq.empty()){
        double len;
        int a, b;
        tie(len, a, b) = pq.top(); pq.pop();
        if(uni(a, b)){
            answer += len;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}