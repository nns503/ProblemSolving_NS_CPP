#include <bits/stdc++.h>
#define H first
#define W second

using namespace std;

int h, w, n;
int answer = 0;

bool validate(pair<int, int> a, pair<int, int> b){
    return (a.H + b.H <= h && max(a.W, b.W) <= w) || (a.W + b.W <= w && max(a.H, b.H) <= h);
}

int solve(int ah, int aw, int bh, int bw){
    if(!validate({ah, aw}, {bh, bw})) return 0;
    return ah*aw + bh*bw;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> n;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        int r, c;
        cin >> r >> c;
        arr[i] = {r, c};
    }

    for(int i=0; i<n; i++){
        auto a = arr[i];
        for(int j=i+1; j<n; j++){
            auto b = arr[j];
            answer = max(solve(a.H, a.W, b.H, b.W), answer);
            answer = max(solve(a.H, a.W, b.W, b.H), answer);
            answer = max(solve(a.W, a.H, b.H, b.W), answer);
            answer = max(solve(a.W, a.H, b.W, b.H), answer);   
        }
    }

    cout << answer;
    return 0;
}