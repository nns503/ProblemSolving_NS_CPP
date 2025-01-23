#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';
    string ab = to_string(a) + to_string(b);
    cout << stoi(ab) - c;
    return 0;
}