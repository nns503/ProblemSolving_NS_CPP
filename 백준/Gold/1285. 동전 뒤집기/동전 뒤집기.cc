#include <bits/stdc++.h>

using namespace std;

int n;
int answer = 1000;
void changeW(string &str){
    for(auto &cur : str){
        if(cur == 'H') cur = 'T';
        else cur = 'H'; 
    }
}

void changeH(int x, vector<string> &str){
    for(int y=0; y<n; y++){
        if(str[y][x] == 'H') str[y][x] = 'T';
        else str[y][x] = 'H';
    }    
}


int getAllT(vector<string> &board){
    int sum = 0;
    for(int x=0; x<n; x++){
        int T = 0;
        for(int y=0; y<n; y++){
            if(board[y][x] == 'T') T++;
        }
        if(n/2 < T) sum += (n - T);
        else sum += T;       
    }
    return sum;
}

void solve(int cnt, vector<string> &board){
    if(cnt >= n){
        answer = min(answer, getAllT(board));
        return ;
    }
    
    changeW(board[cnt]);
    solve(cnt+1, board);
    changeW(board[cnt]);
    solve(cnt+1, board);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> board(n);
    for(auto &cur : board) cin >> cur;

    solve(0, board);
    cout << answer;
    return 0;
}