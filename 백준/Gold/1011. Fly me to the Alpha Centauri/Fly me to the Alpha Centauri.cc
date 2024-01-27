#include <bits/stdc++.h>

using namespace std;

int x, y, T;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        int answer = 1;

        cin >> x >> y;
        int dist = y - x;
        long long index = 0;
        bool c = false;
        int p = 0;
        while(true){
            if(c) c = false;
            else{
                c = true;
                p++;
            }
            index += p;
            if(index >= dist){
                cout << answer << '\n';
                break;
            }
            answer++;
        }
    }
    return 0;
}