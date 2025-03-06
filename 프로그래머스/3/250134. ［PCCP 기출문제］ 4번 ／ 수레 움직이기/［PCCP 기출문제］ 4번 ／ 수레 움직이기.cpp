#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
pair<int, int> desR;
pair<int, int> desB;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<vector<int>> vis;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

int solve(int t, pair<int, int> r, pair<int, int> b){
    if(r == desR && b == desB){
        return t;
    }
    int ans = 0x3f3f3f3f;
    if(r == desR){
        for(int i=0; i<4; i++){
            int nyB = b.Y + dy[i];
            int nxB = b.X + dx[i];
            if(OOB(nyB, nxB)) continue;
            if((vis[nyB][nxB] & 2) == 2) continue;
            if(nyB == r.Y && nxB == r.X) continue;
            vis[nyB][nxB] += 2;
            ans = min(ans, solve(t+1, r, {nyB, nxB}));
            vis[nyB][nxB] -= 2;
        }
    }
    else if(b == desB){
        for(int i=0; i<4; i++){
            int nyR = r.Y + dy[i];
            int nxR = r.X + dx[i];
            if(OOB(nyR, nxR)) continue;
            if((vis[nyR][nxR] & 1) == 1) continue;
            if(nyR == b.Y && nxR == b.X) continue;
            vis[nyR][nxR] += 1;
            ans = min(ans, solve(t+1, {nyR, nxR}, b));
            vis[nyR][nxR] -= 1;
        }
    }
    else{
        for(int i=0; i<4; i++){
            int nyB = b.Y + dy[i];
            int nxB = b.X + dx[i];
            if(OOB(nyB, nxB)) continue;
            if((vis[nyB][nxB] & 2) == 2) continue;
            for(int i=0; i<4; i++){
                int nyR = r.Y + dy[i];
                int nxR = r.X + dx[i];
                if(OOB(nyR, nxR)) continue;
                if((vis[nyR][nxR] & 1) == 1) continue;
                if(nyB == nyR && nxB == nxR) continue;
                if(nyB == r.Y && nxB == r.X && nyR == b.Y && nxR == b.X) continue;
                vis[nyB][nxB] += 2;
                vis[nyR][nxR] += 1;
                ans = min(ans, solve(t+1, {nyR, nxR}, {nyB, nxB}));
                vis[nyB][nxB] -= 2;
                vis[nyR][nxR] -= 1;
            }
        }
    }
    return ans;
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    n = maze.size();
    m = maze[0].size();
    vector<vector<int>> v(n, vector<int>(m, 0));
    vis = v;
    pair<int, int> r;
    pair<int, int> b;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(maze[y][x] == 1){
                vis[y][x] += 1;
                r = {y, x};
            }
            if(maze[y][x] == 2){
                vis[y][x] += 2;
                b = {y, x};
            }
            if(maze[y][x] == 3){
                desR = {y, x};
            }
            if(maze[y][x] == 4){
                desB = {y, x};
            }
            if(maze[y][x] == 5){
                vis[y][x] = 3;
            }
        }
    }
    answer = solve(0, r, b);
    if(answer == 0x3f3f3f3f) answer = 0;
    return answer;
}