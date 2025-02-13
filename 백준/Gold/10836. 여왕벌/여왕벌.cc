#include <bits/stdc++.h>

using namespace std;

int m, n;
int dy[3] = {-1, -1, 0};
int dx[3] = {0, -1, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(m, 1));
    vector<int> grow(2*m, 0);

    int a, b, c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        grow[a]++;
        grow[a+b]++;
    }

    for(int i=1; i<2*m - 1; i++){
        grow[i] += grow[i-1];
    }

    int index = 0;
    for(int y=m-1; y>=0; y--){
        board[y][0] += grow[index++];
    }

    for(int x=1; x<=m-1; x++){
        board[0][x] += grow[index++];
    }

    for(int y=1; y<m; y++){
        for(int x=1; x<m; x++){
            for(int i=0; i<3; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                board[y][x] = max(board[y][x], board[ny][nx]);
            }
        }
    }

    for(int y=0; y<m; y++){
        for(int x=0; x<m; x++){
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
