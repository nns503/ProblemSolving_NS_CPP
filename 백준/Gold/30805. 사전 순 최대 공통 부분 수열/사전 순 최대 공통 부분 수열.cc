#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.A == b.A){
        return a.B < b.B;
    }
    return a.A > b.A;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> a(n);
    for(auto &cur : a) cin >> cur;
    cin >> m;
    vector<int> b(m);
    for(auto &cur : b) cin >> cur;

    vector<int> answer = {};
    vector<pair<int, int>> pq;
    for(int i=0; i<a.size(); i++){
        pq.push_back({a[i], i});
    }
    sort(pq.begin(), pq.end(), cmp);

    int aEn = -1;
    int en = 0;
    for(int i=0; i<pq.size(); i++){
        auto cur = pq[i];
        if(aEn >= cur.B) continue;
        for(int j=en; j<b.size(); j++){
            if(cur.A == b[j]){
                en = j+1;
                aEn = cur.B;
                answer.push_back(cur.A);
                break;
            }
        }
    }

    cout << answer.size() << '\n';
    for(auto cur : answer){
        cout << cur << ' ';
    }
    return 0;
}