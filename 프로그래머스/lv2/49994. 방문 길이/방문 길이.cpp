#include <bits/stdc++.h>
using namespace std;

int k;
bool vis[11][11][4];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool chk(int y, int x){
    return (y<0 || x<0 || y>10 || x>10);
}

int solution(string dirs) {
    int answer = 0;
    int y = 5; 
    int x = 5;
    for(int i=0; i<dirs.size(); i++){
        if(dirs[i] == 'U') k=0;
        else if(dirs[i] == 'R') k=1;
        else if(dirs[i] == 'D') k=2;
        else if(dirs[i] == 'L') k=3;
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(chk(ny, nx)) continue;
        if(!vis[y][x][k] && !vis[ny][nx][(k+2)%4]) answer++;
        vis[ny][nx][(k+2)%4] = true;
        vis[y][x][k] = true;
        y = ny; 
        x = nx;
    }
    return answer;
}