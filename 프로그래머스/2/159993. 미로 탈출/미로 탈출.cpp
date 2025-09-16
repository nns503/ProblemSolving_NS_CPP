#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

int bfs(pair<int, int> st, pair<int, int> en, vector<string> &maps){
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push(st);
    dist[st.Y][st.X] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = dy[i] + cur.Y;
            int nx = dx[i] + cur.X;
            if(OOB(ny, nx)) continue;
            if(maps[ny][nx] == 'X') continue;
            if(dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            q.push({ny, nx});
        }
    }
    
    return dist[en.Y][en.X];
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    pair<int, int> s;
    pair<int, int> l;
    pair<int, int> e;
    
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(maps[y][x] == 'L'){
                l = {y, x};
            }
            if(maps[y][x] == 'E'){
                e = {y, x};
            }
            if(maps[y][x] == 'S'){
                s = {y, x};
            }
        }
    }
    
    int distL = bfs(s, l, maps);
    if(distL == -1){
        return -1;
    }
    int distE = bfs(l, e, maps);
    if(distE == -1){
        return -1;
    }
    answer = distL + distE;
    
    return answer;
}