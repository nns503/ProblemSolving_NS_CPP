#include <bits/stdc++.h>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(vector<string> &board, int y, int x){
    return (y < 0 || y >= board.size() || x < 0 || x >= board[y].size());
}

int find(vector<string> &board, int y, int x){
    int cnt = 0;

    while(true){
        for(int i=0; i<4; i++){
            int ny = y + dy[i] * (cnt+1);
            int nx = x + dx[i] * (cnt+1);
            if(OOB(board, ny, nx) || board[ny][nx] != '*'){
                return cnt;
            }
        }
        cnt++;
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> board(n);

    for(int y=0; y<n; y++){
        cin >> board[y];
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<tuple<int, int ,int>> answer;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x] != '*') continue;
            int cnt = find(board, y, x);
            while(cnt){
                answer.push_back({y+1, x+1, cnt});
                for(int i=0; i<4; i++){
                    int ny = y + dy[i] * cnt;
                    int nx = x + dx[i] * cnt;
                    vis[ny][nx] = true;
                }
                vis[y][x]= true;
                cnt--;
            }
        }
    }

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x] == '*' && !vis[y][x]){
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer.size() << '\n';
    for(auto cur : answer){
        int y, x, cnt;
        tie(y, x, cnt) = cur;
        cout << y << ' ' << x << ' ' << cnt << '\n';
    }
}