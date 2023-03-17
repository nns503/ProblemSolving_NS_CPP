#include<bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int vis[101][101];
queue<pair<int, int>> Q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int solution(vector<vector<int>> maps)
{
    int Y = maps.size();
    int X = maps[0].size();
    Q.push({0, 0});
    vis[0][0] = 1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(ny<0 || nx<0 || ny>=Y || nx>=X) continue;
            if(vis[ny][nx] != 0) continue;
            if(maps[ny][nx] != 1) continue;
            vis[ny][nx] = vis[cur.Y][cur.X] + 1;
            Q.push({ny, nx});
        }
    }
    if(vis[Y-1][X-1] == 0) return -1;
    return vis[Y-1][X-1];
}