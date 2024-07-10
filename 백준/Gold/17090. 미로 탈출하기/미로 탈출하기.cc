#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
vector<bool> escape;

pair<int, int> move(char c){
    if(c == 'U') return {-1, 0};
    else if(c == 'R') return {0, 1};
    else if(c == 'D') return {1, 0};
    else if(c == 'L') return {0, -1};
}

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

bool BFS(int num, int y, int x, vector<string> &board, vector<vector<int>> &vis){
    queue<pair<int, int>> q;
    q.push({y, x});
    vis[y][x] = num;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        auto d = move(board[cur.Y][cur.X]);
        int ny = cur.Y + d.Y;
        int nx = cur.X + d.X;
        if(OOB(ny, nx)){
            return true;
        }
        if(vis[ny][nx] == -1){
            vis[ny][nx] = num;
            q.push({ny, nx});
        }
        else if(vis[ny][nx] == num) continue;
        else{
            if(escape[vis[ny][nx]]){
                return true;
            }
            else{
  
                return false;
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<string> board(n);
    vector<vector<int>> vis(n, vector<int>(m, -1));
     
     for(int y=0; y<n; y++) cin >> board[y];
    int answer = 0;
    int num = 0;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(vis[y][x] != -1){
                answer += escape[vis[y][x]];
                continue;
            }
            escape.push_back(BFS(num, y, x, board, vis));
            answer += escape[vis[y][x]];
            num++;
        }
    }
    cout << answer;
    return 0;
}