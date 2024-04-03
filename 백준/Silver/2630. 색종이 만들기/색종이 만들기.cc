#include <bits/stdc++.h>

using namespace std;

int white, blue;
int board[150][150];

bool sameCheckBoard(int y, int x, int len){
    for(int i=y; i<y+len; i++){
        for(int j=x; j<x+len; j++){
            if(board[y][x] != board[i][j]) return false;
        }
    }
    return true;
}

void func(int y, int x, int len){
    if(sameCheckBoard(y, x, len)){
        if(board[y][x] == 0) white++;
        else blue++;
        return ;
    }
    int l = len/2;
    func(y, x, l);
    func(y, x+l, l);
    func(y+l, x, l);
    func(y+l, x+l, l);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin >> board[y][x];
        }
    }

    func(0, 0, n);

    cout << white << '\n' << blue;
    return 0;
}