#include <bits/stdc++.h>

using namespace std;

long long n;
vector<int> number(6);
vector<int> r = {5, 4, 3, 2, 1, 0};
vector<long long> m(4, 0x3f3f3f3f);
vector<bool> vis(6, false);

void func(int st, int cnt, long long sum){
    m[cnt] = min(m[cnt], sum);
    if(cnt == 3) return;
    for(int i=st; i<6; i++){
        if(vis[i]) continue;
        if(vis[r[i]]) continue; 
        vis[i] = true;
        func(i+1, cnt+1, sum + number[i]);
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(auto &cur : number) cin >> cur;
    long long ans = 0;
    if(n == 1){
        sort(number.begin(), number.end());
        for(int i=0; i<5; i++) ans += number[i];
    }
    else{
        func(0, 0, 0);
        ans = 4 * m[3] + ((n-2) * 4 + (n-1) * 4) * m[2] + (n-1) * (n-2) * m[1] * 4 + (n-2) * (n-2) * m[1];
    }
    cout << ans;
    return 0;
}