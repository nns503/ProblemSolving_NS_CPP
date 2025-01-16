#include <bits/stdc++.h>

using namespace std;

int n, m;

void moveLeft(vector<string> &board){
    for(int y=0; y<board.size(); y++){
        for(int x=0; x<board[y].size(); x++){
            if(board[y][x] == 'R' || board[y][x] == 'B'){
                for(int i=x-1; i>=0; i--){
                    if(board[y][i] == 'O'){
                        board[y][i+1] = '.';
                        break;
                    }
                    if(board[y][i] != '.') break;
                    swap(board[y][i+1], board[y][i]);
                }
            }
        }
    }
}

void moveRight(vector<string> &board){
    for(int y=0; y<board.size(); y++){
        for(int x=board[0].size()-1; x>=0; x--){
            if(board[y][x] == 'R' || board[y][x] == 'B'){
                for(int i=x+1; i<board[0].size(); i++){
                    if(board[y][i] == 'O'){
                        board[y][i-1] = '.';
                        break;
                    }
                    if(board[y][i] != '.') break;
                    swap(board[y][i-1], board[y][i]);
                }
            }
        }
    }    
}

void moveUp(vector<string> &board){
    for(int x=0; x<board[0].size(); x++){
        for(int y=0; y<board.size(); y++){
            if(board[y][x] == 'R' || board[y][x] == 'B'){
                for(int i=y-1; i>=0; i--){
                    if(board[i][x] == 'O'){
                        board[i+1][x] = '.';
                        break;
                    }
                    if(board[i][x] != '.') break;
                    swap(board[i+1][x], board[i][x]);
                }
            }
        }
    }
}

void moveDown(vector<string> &board){
    for(int x=0; x<board[0].size(); x++){
        for(int y=board.size()-1; y>=0; y--){
            if(board[y][x] == 'R' || board[y][x] == 'B'){
                for(int i=y+1; i<board.size(); i++){
                    if(board[i][x] == 'O'){
                        board[i-1][x] = '.';
                        break;
                    }
                    if(board[i][x] != '.') break;
                    swap(board[i-1][x], board[i][x]);
                }
            }
        }
    }
}

bool validateBoard(vector<string> &board){
    bool red = false;
    bool blue = false;
    for(int y=0; y<board.size(); y++){
        for(int x=0; x<board[y].size(); x++){
            if(board[y][x] == 'R') red = true;
            if(board[y][x] == 'B') blue = true;
        }
    }
    if(!red && blue) return true;
    return false;
}

void drawBoard(vector<string> &board){
    for(int y=0; y<n; y++){
        cout << board[y] << '\n';
    }    
    cout << "---------------\n";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<string> board(n);
    map<vector<string>, int> dist;
    queue<vector<string>> q;
    for(int y=0; y<n; y++){
        cin >> board[y];
    }
    dist[board] = 0;
    q.push(board);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            vector<string> temp = cur;
            if(i == 0) moveLeft(temp);
            if(i == 1) moveRight(temp);
            if(i == 2) moveUp(temp);
            if(i == 3) moveDown(temp);
            if(dist.find(temp) != dist.end()) continue;
            if(validateBoard(temp)){
                cout << 1;
                return 0;
            }
            if(dist[cur] + 1 >= 10) continue;
            dist[temp] = dist[cur] + 1;
            q.push(temp);
        }
    }
    
    cout << 0;
    
    return 0;
}