#include <bits/stdc++.h>

using namespace std;

int n;
int board[2501][2501];
int a, b, c;

void func(int y, int x, int len){
    int cur = board[y][x];
    for(int i=y; i<y+len; i++){
        for(int j=x; j<x+len; j++){
            if(cur != board[i][j]){
                int l = len/3;
                func(y, x, l);
                func(y, x+l, l);
                func(y, x+l*2, l);
                func(y+l, x, l);
                func(y+l*2, x, l);
                func(y+l, x+l, l);
                func(y+l, x+l*2, l);
                func(y+l*2, x+l, l);
                func(y+l*2, x+l*2, l);
                return;
            }
        }
    }
    if(cur == -1) a++;
    else if(cur == 0) b++;
    else if(cur == 1) c++;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    func(0, 0, n);
    cout << a << '\n' << b << '\n' << c;
    return 0;
}

