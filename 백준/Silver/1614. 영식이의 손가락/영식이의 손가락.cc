#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p;
    long long n;
    cin >> p >> n;

    if(p == 1){
        cout << n * 8;
    }
    else if(p == 5){
        cout << n * 8 + 4;
    }
    else if(p == 2){
        if(n % 2){
            cout << n * 4 + 3;
        }
        else cout << n * 4 + 1;
    }
    else if(p == 4){
        if(n % 2){
            cout << n  * 4 + 1;
        }
        else cout << n * 4 + 3;
    }
    else{
        cout << n * 4 + 2;
    }

    return 0;
}