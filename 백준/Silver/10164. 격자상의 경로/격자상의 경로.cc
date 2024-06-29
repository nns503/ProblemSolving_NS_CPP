#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, k;

int getLen(pair<int, int> st, pair<int, int> en){
    vector<vector<int>> board(n+1, vector<int>(m+1, 0));

    board[st.Y][st.X] = 1;
    for(int y=st.Y; y<=en.Y; y++){
        for(int x=st.X; x<=en.X; x++){
            board[y][x] += board[y-1][x];
            board[y][x] += board[y][x-1];
        }
    }

    return board[en.Y][en.X];
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    int ans = 0;
    if(k != 0){
        ans = getLen({1, 1}, {(k-1) / m + 1, (k-1) % m + 1});
        ans *= getLen({(k-1) / m + 1, (k-1) % m + 1}, {n, m});
    }
    else ans = getLen({1, 1}, {n, m});

    cout << ans;
}