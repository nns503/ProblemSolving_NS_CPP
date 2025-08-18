#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int dy[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int r, c;
pair<int, int> jongsu;

int getLen(int y, int x){
    return abs(y - jongsu.Y) + abs(x - jongsu.X);
}

vector<string> solve(vector<string> &board, string str){
    vector<string> answer;
    // 종수가 어딨는지 기록합니다.
    for(int y=0; y<r; y++){
        for(int x=0; x<c; x++){
            if(board[y][x] == 'I'){
                jongsu = {y, x};
            }
        }
    }

    for(int i=0; i<str.size(); i++){
        int move = str[i] - '0'; // 움직임 방향 

        // 1 + 2. 종수야 움직여
        if(board[jongsu.Y + dy[move]][jongsu.X + dx[move]] == 'R'){ // 미친 아두이노로 가면 종료
            answer.push_back("kraj " + to_string(i+1));
            return answer;
        }
        else{ // 아니면 이동시킴
            board[jongsu.Y][jongsu.X] = '.';
            jongsu = {jongsu.Y + dy[move], jongsu.X + dx[move]};
            board[jongsu.Y][jongsu.X] = 'I';
        }
    
        map<pair<int, int>, int> cnt; // 해당 지점의 아두이노 개수
        vector<string> tempBoard(r); 
        for(int y=0; y<r; y++){
            tempBoard[y] = board[y];
        }
        
        // 아두이노 찾기
        for(int y=0; y<r; y++){
            for(int x=0; x<c; x++){
                // 미친 아두이노인 경우
                if(board[y][x] == 'R'){
                    // 3.미친 아두이노는 종수한테 이동
                    int temp = 0x3f3f3f3f; // 종수와의 거리
                    pair<int, int> movePoint = {y, x}; // 미친 아두이노 이동 임시 위치
                    for(int d=1; d<=9; d++){
                        if(d == 5) continue;
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(temp > getLen(ny, nx)){
                            temp = getLen(ny, nx);
                            movePoint.Y = ny;
                            movePoint.X = nx;
                        }
                    }
                    
                    // 4. 종수가 있는 자리면 종료
                    if(tempBoard[movePoint.Y][movePoint.X] == 'I'){
                        answer.push_back("kraj " + to_string(i+1));
                        return answer;
                    }

                    // 종수가 없으면 이동시키되, 그 해당 지점의 미친 아두이노 개수를 기록함
                    else{
                        tempBoard[movePoint.Y][movePoint.X] = 'R';
                        cnt[movePoint]++;
                    }
                }
            }
        }

        for(int y=0; y<r; y++){
            for(int x=0; x<c; x++){
                if(cnt[{y, x}] == 1){ // 한개면 미친 아두이노 배치
                    board[y][x] = 'R';
                }
                else board[y][x] = '.'; // 아니면 그냥 . 처리 (2개 이상이면 폭파하기 때문) 
            }
        }
        board[jongsu.Y][jongsu.X] = 'I'; // 방금 위에서 종수 위치 지워버림 ㅠㅠ
    }

    return board;

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    vector<string> board(r);
    for(int y=0; y<r; y++) cin >> board[y];
    string str;
    cin >> str;

    vector<string> answer = solve(board, str);
    for(auto cur : answer){
        cout << cur << '\n';
    }

    return 0;
}