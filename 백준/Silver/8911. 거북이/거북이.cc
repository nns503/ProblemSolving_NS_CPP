#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        vector<int> p(4, 0);
        pair<int, int> cur;
        int curD = 0;
        string str;
        cin >> str;
        for(auto op : str){
            if(op == 'F' || op == 'B'){
                int d;
                if(op == 'F') d = curD;
                else d = (curD + 2) % 4;
                cur.Y += dy[d];
                cur.X += dx[d];
                if(d == 0){
                    p[d] = max(p[d], cur.Y);
                }
                else if(d == 1){
                    p[d] = max(p[d], cur.X);
                }
                else if(d == 2){
                    p[d] = min(p[d], cur.Y);
                }
                else if(d == 3){
                    p[d] = min(p[d], cur.X);
                }
            }
            else if(op == 'R'){
                curD = (curD + 1) % 4;
            }
            else if(op == 'L'){
                curD = (curD + 3) % 4;
            }
        }
        cout << (p[0] - p[2]) * (p[1] - p[3]) << '\n';
    }
}