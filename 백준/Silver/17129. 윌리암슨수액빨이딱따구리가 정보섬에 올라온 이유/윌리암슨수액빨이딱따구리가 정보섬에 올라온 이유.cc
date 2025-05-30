#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

vector<vector<int>> solve(pair<int, int> st, vector<string> &board){
    vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));
    queue<pair<int, int>> q;
    dist[st.Y][st.X] = 0;
    q.push({st.Y, st.X});

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == '1') continue;
            if(dist[ny][nx] != 0x3f3f3f3f) continue;
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            q.push({ny, nx});
        }
    }

    return dist;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<string> board(n);

    for(auto &cur : board){
        cin >> cur;
    }
    
    int stY, stX;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x] == '2'){
                stY = y;
                stX = x;
            }
        }
    }

    int answer = 0x3f3f3f3f;
    vector<vector<int>> dist = solve({stY, stX}, board);
    
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x] == '3' || board[y][x] == '4' || board[y][x] == '5'){
                answer = min(answer, dist[y][x]);
            }
        }
    }

    if(answer == 0x3f3f3f3f){
        cout << "NIE";
    }
    else{
        cout << "TAK" << '\n' << answer;
    }
}