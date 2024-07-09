#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

string k, s;
int n;

pair<int, int> move(string d){
    if(d == "R") return {0, 1};
    else if(d == "L") return {0, -1};
    else if(d == "B") return {-1, 0};
    else if(d == "T") return {1, 0};
    else if(d == "RT") return {1, 1};
    else if(d == "LT") return {1, -1};
    else if(d == "RB") return {-1, 1};
    else if(d == "LB") return {-1, -1};
}

bool OOB(int ny, char nx){
    return (ny > 8 || ny < 1 || nx < 'A' || nx > 'H');
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> s >> n;
    string d;
    pair<int, char> kp = {k[1] - '0', k[0]};
    pair<int, char> sp = {s[1] - '0', s[0]};

    while(n--){
        cin >> d;
        pair<int, int> mv = move(d);
        int ny = kp.Y + mv.Y;
        char nx = kp.X + mv.X;
        if(OOB(ny, nx)) continue;
        if(ny == sp.Y && nx == sp.X){
            int sy = sp.Y + mv.Y;
            char sx = sp.X + mv.X;
            if(OOB(sy, sx)) continue;
            sp = {sy, sx};
        }
        kp = {ny, nx};
    }

    cout << kp.X << kp.Y << '\n';
    cout << sp.X << sp.Y << '\n';

    return 0;
}
