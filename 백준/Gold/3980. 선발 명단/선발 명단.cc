#include <bits/stdc++.h>

using namespace std;

int c;
int player[12][12];
bool position[12];
int answer;

void func(int cnt, int sum){
    if(cnt == 11){
        answer = max(sum, answer);
        return ;
    }

    for(int i=0; i<11; i++){
        if(position[i]) continue;
        if(player[cnt][i] == 0) continue;
        position[i] = true;
        func(cnt+1, sum+player[cnt][i]);
        position[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c;

    while(c--){
        answer = 0;
        for(int i=0; i<11; i++){
            for(int j=0; j<11; j++){
                cin >> player[i][j];
            }
        }

        func(0, 0);
        cout << answer << '\n';
    }
    return 0;
}