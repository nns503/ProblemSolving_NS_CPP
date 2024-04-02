#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int cnt = 0;
int Z(int y, int x, int len, int num){
    if(y == r && x == c) return num;
    

    int l = len/2;
    int mul = len * len / 4;
    
    if(l + y> r && l + x> c) return Z(y, x, l, num);
    else if(l + y> r && l + x<= c) return Z(y, x+l, l, num + mul);
    else if(l + y <= r && l + x> c) return Z(y+l, x, l, num + mul*2);
    else if(l + y<= r && l + x<= c) return Z(y+l, x+l, l, num + mul*3);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    cout << Z(0, 0, (1<<n), 0);
    return 0;
}
