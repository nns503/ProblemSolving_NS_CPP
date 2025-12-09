#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int r, c;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= r || x >= c);
}

void initAnimals(vector<string> &board, vector<int> &answer){
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(board[y][x] == 'o') answer[0]++;
            else if(board[y][x] == 'v') answer[1]++;
        }
    }
}

void killAnimals(pair<int, int> point, vector<string> &board, vector<vector<bool>> &vis, vector<int> &answer){
    vis[point.Y][point.X] = true;
    queue<pair<int, int>> q;
    q.push(point);
    int sheep = 0;
    int wolf = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(board[cur.Y][cur.X] == 'o') sheep++;
        else if(board[cur.Y][cur.X] == 'v') wolf++;

        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == '#') continue;
            if(vis[ny][nx]) continue;
            q.push({ny, nx});
            vis[ny][nx] = true;
        } 
    }

    if(sheep > wolf) answer[1] -= wolf;
    else answer[0] -= sheep;
}

vector<int> solve(vector<string> &board){
    vector<int> answer(2, 0);
    initAnimals(board, answer);

    vector<vector<bool>> vis(r, vector<bool>(c, false));
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(vis[y][x]) continue;
            if(board[y][x] == '#' || board[y][x] == '.') continue;
            killAnimals({y, x}, board, vis, answer);
        }
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    vector<string> board(r);
    for(auto &cur : board){
        cin >> cur;
    }

    vector<int> answer = solve(board);
    cout << answer[0] << ' ' << answer[1];

    return 0;
}