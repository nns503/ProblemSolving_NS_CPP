#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n+1, vector<int>(n+1));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> board[i][j];
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int dist = board[i][k] + board[k][j];
                if(board[i][j] > dist){
                    board[i][j] = dist;
                }
            }
        }
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << (board[a][b] <= c ? "Enjoy other party\n" : "Stay here\n");
    }
}