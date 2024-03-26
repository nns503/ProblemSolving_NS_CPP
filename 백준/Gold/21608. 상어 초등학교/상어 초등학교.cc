#include <bits/stdc++.h>

using namespace std;

int n;
int board[21][21];
int arr[401][4];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
    return (y <= 0 || x <= 0 || y > n || x > n);
}

int getFriend(int y, int x, int index){
    int sum = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        if(find(arr[index], arr[index]+4, board[ny][nx]) != arr[index]+4) sum++;
    }
    return sum;
}

int getEmpty(int y, int x){
    int sum = 0;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(OOB(ny, nx)) continue;
        if(board[ny][nx] == 0) sum++;
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n*n; i++){
        int num;
        cin >> num;
        for(int j=0; j<4; j++){
            cin >> arr[num][j];
        }
        int f = 0, em = -1, curY = 0, curX = 0;
        for(int y=1; y<=n; y++){
            for(int x=1; x<=n; x++){
                if(board[y][x] != 0) continue;
                int getEm = getEmpty(y, x);
                int getFr = getFriend(y, x, num);
                if(getFr > f || (getFr == f && getEm > em)){
                    f = getFr; em = getEm; curY = y; curX = x;
                }
            }
        }
        board[curY][curX] = num;
    }

    int answer = 0;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            int getFr = getFriend(y, x, board[y][x]);
            if(getFr != 0) answer += pow(10, getFr-1);
        }
    }

    cout << answer;
    return 0;
}