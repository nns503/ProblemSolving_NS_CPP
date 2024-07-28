#include <bits/stdc++.h>

using namespace std;

const long long MAX_NUM = 1000000000000;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ha;
    long long hp = MAX_NUM;
    long long mn =  MAX_NUM;

    cin >> n >> ha;

    while(n--){
        long long t, a, h;
        cin >> t >> a >> h;

        if(t == 1){
            hp -= (h / ha) * a;
            if(h % ha == 0) hp += a;
        }
        else if(t == 2){
            ha += a;
            hp += h;
            if(hp > MAX_NUM) hp = MAX_NUM;
        }

        mn = min(mn, hp);
    }

    cout << MAX_NUM - mn + 1;
    
    return 0;
}