#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int answer = 0;
int n, m;
bool vis[6][6];
int board[6][6];

vector<vector<pair<int, int>>> arr = {
        {{0, -1}, {0, 0}, {1, 0}},
        {{-1, 0}, {0, 0}, {0, -1}},
        {{-1, 0}, {0, 0}, {0, 1}},
        {{1, 0}, {0, 0}, {0, 1}}
    };

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

bool continueCheck(int y, int x, int i){
    for(int j=0; j<3; j++){
        int ny = y + arr[i][j].Y;
        int nx = x + arr[i][j].X;
        if(OOB(ny, nx) || vis[ny][nx]){
            return true;
        }
    }

    return false;
}

void solve(int sum, int h, int w){
    if(w >= m){
        w = 0;
        h++;
    }
    if(h >= n){
        answer = max(answer, sum);
        return;
    }

    if(!vis[h][w]){
        for(int i=0; i<4; i++){

            if(continueCheck(h, w, i)){
                continue;
            }

            int temp = 0;
            for(int j=0; j<3; j++){
                int ny = h + arr[i][j].Y;
                int nx = w + arr[i][j].X;
                if(j == 1) temp += board[ny][nx];
                temp += board[ny][nx];
                
                vis[ny][nx] = true;
            }

            solve(sum + temp, h, w+1);

            for(int j=0; j<3; j++){
                int ny = h + arr[i][j].Y;
                int nx = w + arr[i][j].X;

                vis[ny][nx] = false;
            }
        }
    }

    solve(sum, h, w+1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;


    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin >> board[y][x];
        }
    }

    
    solve(0, 0, 0);

    cout << answer;

    return 0;
}