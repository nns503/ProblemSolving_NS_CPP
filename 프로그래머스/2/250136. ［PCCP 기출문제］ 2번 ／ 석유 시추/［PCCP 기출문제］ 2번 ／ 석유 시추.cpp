#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int h, w;
int t = 0;
map<int, int> m;

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= h || x >= w);
}

void setBoard(vector<vector<int>> &land, vector<vector<int>> &num, int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    num[y][x] = t;
    int cnt = 0; 
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(num[ny][nx] != -1) continue;
            if(land[ny][nx] == 0) continue;
            num[ny][nx] = t;
            q.push({ny, nx});
        }
    }
    m[t] = cnt;
    t++;
}

int getCount(vector<vector<int>> &num, int x){
    int cnt = 0;
    set<int> s;
    for(int y=0; y<h; y++){
        if(num[y][x] == -1) continue;
        s.insert(num[y][x]);
    }
    for(auto x : s){
        cnt += m[x];
    }
    
    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    h = land.size();
    w = land[0].size();
    vector<vector<int>> num(h, vector<int>(w, -1));
    
    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            if(land[y][x] == 0) continue;
            if(num[y][x] == -1){
                setBoard(land, num, y, x);
            }
        }
    }
    
    for(int x=0; x<w; x++){
        answer = max(answer, getCount(num, x));
    }
    
    return answer;
}