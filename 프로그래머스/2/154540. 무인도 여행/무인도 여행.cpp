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

int bfs(pair<int, int> st, vector<string> &maps, vector<vector<bool>> &vis){
    vis[st.Y][st.X] = true;
    queue<pair<int, int>> q;
    q.push(st);
    
    int sum = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        sum += maps[cur.Y][cur.X] - '0';
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(maps[ny][nx] == 'X') continue;
            if(vis[ny][nx]) continue;
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(vis[y][x]) continue;
            if(maps[y][x] == 'X') continue;
            int sum = bfs({y, x}, maps, vis);
            answer.push_back(sum);
        }
    }
    
    if(answer.empty()){
        answer.push_back(-1);
        return answer;
    }
    sort(answer.begin(), answer.end());
    return answer;
}