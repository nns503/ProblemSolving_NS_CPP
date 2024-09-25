#include <bits/stdc++.h>

using namespace std;

int findP(vector<int> &p, int x){
    if(p[x] == x) return x;
    return p[x] = findP(p, p[x]);
}

void uni(vector<int> &p, int a, int b){
    a = findP(p, a);
    b = findP(p, b);

    if(a != b) p[a] = b;
}

bool isLen(tuple<int, int, int> cur, tuple<int, int, int> nxt){
    int curX, curY, curR;
    int nxtX, nxtY, nxtR;
    tie(curX, curY, curR) = cur;
    tie(nxtX, nxtY, nxtR) = nxt;
    return (pow(nxtX-curX, 2) + pow(nxtY-curY, 2)) <= pow(curR + nxtR, 2);
}

int solve(vector<tuple<int, int, int>> &arr){
    vector<int> p(arr.size());
    for(int i=0; i<p.size(); i++) p[i] = i;

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(isLen(arr[i], arr[j])){
                uni(p, i, j);
            } 
        }
    }

    set<int> chk;
    for(auto &cur : p){
        int f = findP(p, cur);
        if(chk.find(f) == chk.end()){
            chk.insert(f);
        }
    }
    return chk.size();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<tuple<int, int, int>> arr(n);
        for(auto &cur : arr){
            int x, y, r;
            cin >> x >> y >> r;
            cur = {x, y, r};
        }
        cout << solve(arr) << '\n';

    }
    return 0;
}