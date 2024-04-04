#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> point(n);

    for(auto &cur : point){
        cin >> cur.X >> cur.Y;
    }

    sort(point.begin(), point.end());

    for(auto cur : point){
        cout << cur.X << ' ' << cur.Y << '\n';
    }
    return 0;
}