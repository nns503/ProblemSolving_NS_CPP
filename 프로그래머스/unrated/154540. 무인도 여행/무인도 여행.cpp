#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int board[101][101];
bool vis[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int my, mx;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= my || x >= mx);
}

int BFS(pair<int, int> p){
    q.push(p);
    vis[p.Y][p.X] = true;
    int sum = board[p.Y][p.X];
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(vis[ny][nx]) continue;
            if(board[ny][nx] == -1) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
            sum += board[ny][nx];
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    my = maps.size(); mx = maps[0].size();
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] == 'X') board[i][j] = -1;
            else board[i][j] = maps[i][j] - '0';
        }
    }
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] == 'X' || vis[i][j]) continue;
            answer.push_back(BFS({i, j}));
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}