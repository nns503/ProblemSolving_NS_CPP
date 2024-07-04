#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int n, m;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= m || x >= n);
}

int getPower(pair<int, int> p, vector<string> &board, vector<vector<bool>> &vis){
    int cnt = 0;
    
    vis[p.Y][p.X] = true;
    queue<pair<int, int>> q;
    q.push({p.Y, p.X});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[p.Y][p.X] != board[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<string> board(m);
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for(auto &cur : board){
        cin >> cur;
    }
    
    int ans[2] = {0, 0}; 

    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(vis[y][x]) continue;
            int g = getPower({y, x}, board, vis);
            if(board[y][x] == 'W'){
                ans[0] += g*g;
            }
            else ans[1] += g*g;
        }   
    }
  
    cout << ans[0] << ' ' << ans[1];
    return 0;
}
