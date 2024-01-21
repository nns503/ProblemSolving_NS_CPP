#include <bits/stdc++.h>

using namespace std;

int n;
int d[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    d[1] = 3; d[2] = 7;
    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] * 2 + d[i-2]) % 9901;
    }

    cout << d[n];

    return 0;
}
