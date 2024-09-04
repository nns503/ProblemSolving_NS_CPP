#include <bits/stdc++.h>

using namespace std;

int m, n;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y < 0 || x < 0 || y >= m || x >= m);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    vector<vector<int>> board(m, vector<int>(m, 1));
    vector<vector<int>> temp(m, vector<int>(m));
    while(n--){
        vector<int> arr(3);
        for(int y=0; y<m; y++){
            for(int x=0; x<m; x++){
                temp[y][x] = board[y][x];
            }
        }
        cin >> arr[0] >> arr[1] >> arr[2];
        int index = 0;
        for(int y=m-1; y>=0; y--){
            while(arr[index] == 0){
                index++;
            }
            board[y][0] += index;
            arr[index]--;
        }

        for(int x=1; x<m; x++){
            while(arr[index] == 0){
                index++;
            }
            board[0][x] += index;
            arr[index]--;
        }

        for(int y=1; y<m; y++){
            for(int x=1; x<m; x++){
                int score = 0;
                for(int i=0; i<4; i++){
                    int ny = dy[i] + y;
                    int nx = dx[i] + x;
                    if(OOB(ny, nx)) continue;
                    score = max(score, board[ny][nx] - temp[ny][nx]);
                }
                board[y][x] += score;
            }
        }
    }

    for(int y=0; y<m; y++){
        for(int x=0; x<m; x++){
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }
    return 0;
}