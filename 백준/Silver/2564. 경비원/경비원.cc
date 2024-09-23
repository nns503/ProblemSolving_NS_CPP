#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

bool chk(int a, int b){
    if(a == 1 || a == 2){
        if(b == 1 || b == 2) return true;
        else return false;
    }
    else{
        if(b == 3 || b == 4) return true;
        else return false;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, n;
    cin >> x >> y >> n;
    vector<pair<int, int>> arr(n);
    for(auto &cur : arr){
        cin >> cur.Y >> cur.X;
    }
    pair<int, int> p;
    cin >> p.Y >> p.X;

    int answer = 0;
    for(auto &cur : arr){
        int d = cur.Y;
        int len = cur.X;
        if(chk(d, p.Y)){
            if(p.Y == d) answer += abs(len - p.X);
            else{
                if(d == 1 || d == 2){
                    answer += min(len + p.X, 2*x - len - p.X) + y;
                }
                else{
                    answer += min(len + p.X, 2*y - len - p.X) + x;
                }
            }
        }
        else{
            if(p.Y == 1){
                if(d == 3){
                    answer += p.X + len;
                }
                else if(d == 4){
                    answer += x - p.X + len;
                }
            }
            else if(p.Y == 2){
                if(d == 3){
                    answer += p.X + y - len;
                }
                else if(d == 4){
                    answer += x - p.X + y - len;
                }
            }
            else if(p.Y == 3){
                if(d == 1){
                    answer += p.X + len;
                }
                else if(d == 2){
                    answer += y - p.X + len;
                }
            }
            else if(p.Y == 4){
                if(d == 1){
                    answer += p.X + x - len;
                }
                else if(d == 2){
                    answer += y - p.X + x - len;
                }
            }
        }
    }

    cout << answer;
    
    return 0;
}