#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.Y == p2.Y) return p1.X < p2.X;
    return p1.Y < p2.Y;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> point(n);

    for(auto &cur : point){
        cin >> cur.X >> cur.Y;
    }

    sort(point.begin(), point.end(), cmp);

    for(auto cur : point){
        cout << cur.X << ' ' << cur.Y << '\n';
    }
    return 0;
}