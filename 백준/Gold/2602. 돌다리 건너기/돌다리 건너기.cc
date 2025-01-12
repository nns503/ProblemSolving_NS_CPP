#include <bits/stdc++.h>

using namespace std;

string target, a, b;
int memo[101][2][21];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> target >> a >> b;

    for(int y=0; y<2; y++){
        string cur;
        if(y == 0) cur = a;
        else cur = b;
        for(int x=0; x<a.size(); x++){
            if(x != 0 ) memo[x][y][0] = memo[x-1][y][0];
            if(cur[x] == target[0]){
                memo[x][y][0]++;
            }
        }
    }

    for(int i=1; i<target.size(); i++){
        for(int y=0; y<2; y++){
            string cur;
            if(y == 0) cur = a;
            else cur = b;
            for(int x=i; x<a.size(); x++){
                memo[x][y][i] = memo[x-1][y][i];
                if(cur[x] == target[i]){
                    memo[x][y][i] += memo[x-1][(y + 1) % 2][i-1];
                }
            }
        }
    }

    int answer = 0;
    for(int y=0; y<2; y++){
        answer += memo[a.size()-1][y][target.size()-1];
    }

    cout << answer;

    return 0;
}