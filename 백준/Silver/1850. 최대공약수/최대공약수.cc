#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a, b;
int len;

ll GCD(ll a, ll b){
    if(a % b == 0) return b;
    return GCD(b, a%b);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    if(a < b) swap(a, b);
    len = GCD(a, b);
    for(int i=0; i<len; i++) cout << 1;
    return 0;
}