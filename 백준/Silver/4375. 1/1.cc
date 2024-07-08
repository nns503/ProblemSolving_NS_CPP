#include <bits/stdc++.h>

using namespace std;

int solve(int n){
    unsigned long long x = 1;
    int cnt = 1;
    while(x % n != 0){
        x *= 10;
        x += 1;
        x %= n;
        cnt++;
    }

    return cnt;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(true){
        cin >> n;
        if(cin.eof()) break;
        cout << solve(n) << '\n';
        
    }
    return 0;
}