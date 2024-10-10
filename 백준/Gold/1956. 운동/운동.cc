#include <bits/stdc++.h>

using namespace std;

int v, e;
int board[401][401];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            board[i][j] = 0x3f3f3f3f;
            if(i == j) board[i][j] = 0;
        }
    }

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(i == j) continue;
                if(board[i][j] > board[i][k] + board[k][j]){
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }

    int answer = 0x3f3f3f3f * 2;

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i == j) continue;
            answer = min(answer, board[i][j] + board[j][i]);
        }
    }

    if(answer >= 0x3f3f3f3f) answer = -1;
    cout << answer ;
    return 0;
}