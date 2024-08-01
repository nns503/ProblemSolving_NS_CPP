#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, d;
int dy[3] = {0, -1, 0};
int dx[3] = {-1, 0, 1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

int moveBoard(vector<vector<int>> &board){
    int cnt = 0;

    for(int x=0; x<m; x++){
        if(board[n-1][x] == 1) cnt++;
        for(int y=n-1; y>=1; y--){
            board[y][x] = board[y-1][x];
        }
        board[0][x] = 0;
    }

    return cnt;
}

pair<int, int> BFS(vector<vector<int>> &board, pair<int, int> st){
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    dist[st.Y][st.X] = 1;
    q.push({st.Y, st.X});

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        if(board[cur.Y][cur.X] == 1){
            return {cur.Y, cur.X};
        }

        for(int i=0; i<3; i++){
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];

            if(OOB(ny, nx)) continue;
            if(dist[ny][nx] != 0) continue;
            if(dist[cur.Y][cur.X] + 1 > d){
                dist[ny][nx] = -1;
                continue;
            }
            q.push({ny, nx});
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
        }
    }

    return {-1, -1};
}

int solve(vector<vector<int>> &board, int cnt, vector<int> &archer){
    int answer = 0;
    stack<pair<int, int>> stk;
    while(cnt > 0){
        for(auto arc : archer){
            auto p = BFS(board, {n-1, arc});
            if(p.Y == -1) continue;
            else stk.push({p});
        }
        while(!stk.empty()){
            auto p = stk.top(); stk.pop();
            if(board[p.Y][p.X] == 1){
                board[p.Y][p.X] = 0;
                answer++;
                cnt--;
            }
        }
        cnt -= moveBoard(board);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int answer = 0;
    cin >> n >> m >> d;

    vector<vector<int>> board(n, vector<int>(m));
    vector<int> arr(m, 0);

    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin >> board[y][x];
            if(board[y][x] == 1) cnt++;
        }
    }


    for(int x=m-1; x>=m-3; x--) arr[x] = 1;

    do{
        vector<int> archer;
        for(int i=0; i<m; i++){
            if(arr[i] == 1){
                archer.push_back(i);
            }    
        }
        vector<vector<int>> temp(n, vector<int>(m));
        copy(board.begin(), board.end(), temp.begin());
        answer = max(solve(temp, cnt, archer), answer);
    }while(next_permutation(arr.begin(), arr.end()));

    cout << answer;

    return 0;
}