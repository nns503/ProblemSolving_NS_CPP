#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int board[11][11];
int vis[11][11];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int answer = -0x3f3f3f3f;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

void setVisit(int y, int x, int state){
    vis[y][x] += state;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        vis[ny][nx] += state;
    }
}
void func(int sum, int cnt, int p){
    if(cnt == k){
        answer = max(sum, answer);
        return;
    }

    for(int i=p; i<n*m; i++){
        int y = i / m;
        int x = i % m;
        if(vis[y][x] > 0) continue;
        setVisit(y, x, 1);
        func(sum + board[y][x], cnt+1, i+1);
        setVisit(y, x, -1); 
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> board[i][j];
    }

    func(0, 0, 0);

    cout << answer;

    return 0;
}