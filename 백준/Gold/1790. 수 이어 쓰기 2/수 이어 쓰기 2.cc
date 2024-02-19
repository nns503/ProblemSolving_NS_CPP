#include <bits/stdc++.h>

using namespace std;

int n, k;

int func(int x){
    int p = 1;
    int target = 1;
    while(9 * pow(10, p-1) * (p) < x){
        x -= 9 * pow(10, p-1) * (p);
        target = 10 * pow(10, p-1);
        p++;
    }

    target += (x - 1) / p;
    if(target > n) return -1;
    int d = (x-1) % p;
    string temp = to_string(target);
    int answer = temp[d] - '0';
    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cout << func(k);

    return 0;
}