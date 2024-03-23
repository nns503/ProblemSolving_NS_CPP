#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int r, c;
bool chk[4];
char board[26][26];
int vis[26][26];
queue<pair<int, int>> q;
vector<pair<int, int>> pipe[7] = {
    {{-1, 0}, {1, 0}},
    {{0, -1}, {0, 1}},
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
    {{1, 0}, {0, 1}},
    {{-1, 0}, {0, 1}},
    {{0, -1}, {-1, 0}},
    {{0, -1}, {1, 0}}
};
unordered_map<char, int> p = {{'|', 0}, {'-', 1}, {'+', 2}, {'1', 3}, {'2', 4}, {'3', 5}, {'4', 6}};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y <= 0 || x <= 0 || y > r || x > c);
}

char func(int y, int x){
    
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        char cur = board[ny][nx];
        if(cur == '.') continue;
        if(cur == 'M' || cur == 'Z') continue;
        if(i == 0){
            if(cur != '+' && cur != '|' && cur != '1' && cur != '4') continue;
        }
        else if(i == 1){
            if(cur != '+' && cur != '|' && cur != '2' && cur != '3') continue;
        }
        else if(i == 2){
            if(cur != '+' && cur != '-' && cur != '3' && cur != '4') continue;
        }
        else if(i == 3){
            if(cur != '+' && cur != '-' && cur != '1' && cur != '2') continue;
        } 
        chk[i] = true;
    }

    if(chk[0] && chk[1] && chk[2] && chk[3]) return '+';
    if(chk[0] && chk[1]) return '|';
    if(chk[2] && chk[3]) return '-';
    if(chk[1] && chk[2]) return '1';
    if(chk[2] && chk[0]) return '2';
    if(chk[3] && chk[0]) return '3';
    if(chk[3] && chk[1]) return '4';
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(board[i][j] == 'M' || board[i][j] == 'Z'){    
                vis[i][j]++;
                for(int k=0; k<4; k++){
                    int ny = i + pipe[2][k].Y;
                    int nx = j + pipe[2][k].X;
                    if(OOB(ny, nx)) continue;
                    if(board[ny][nx] == '.') continue;
                    if(board[ny][nx] == 'M' || board[ny][nx] == 'Z') continue;
                    q.push({ny, nx});
                    vis[ny][nx]++;
                }
            }
            
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int num = p[board[cur.Y][cur.X]];
        for(int i=0; i<pipe[num].size(); i++){
            int ny = cur.Y + pipe[num][i].Y;
            int nx = cur.X + pipe[num][i].X;
            if(OOB(ny, nx)) continue;
            if(board[ny][nx] == '.'){
                if(vis[ny][nx] == 1){
                    cout << ny << ' ' << nx << ' ';
                    for(int k=0; k<7; k++){
                        cout << func(ny, nx);
                        return 0;
                    }
                }  
                else{
                    q.push({ny, nx});
                    vis[ny][nx]++;
                }
            }  
            else{
                if(vis[ny][nx] >= 1) continue;
                q.push({ny, nx});
                vis[ny][nx]++;
            }
        }
    }
    return 0;
}