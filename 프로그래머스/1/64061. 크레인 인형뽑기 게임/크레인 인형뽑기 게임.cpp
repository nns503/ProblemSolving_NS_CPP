#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    stack<int> stk;
    
    for(auto mv : moves){
        // 1. 뽑기
        int cur = 0;
        for(int i=0; i<=n-1; i++){
            if(board[i][mv-1] == 0) continue;
            cur = board[i][mv-1];
            board[i][mv-1] = 0;
            break;
        }
        if(cur == 0) continue;
        // 2. 바구니
        if(stk.empty()){
            stk.push(cur);
            continue;
        }
        auto prv = stk.top();
        if(prv == cur){
            answer += 2;
            stk.pop();
            continue;
        }
        stk.push(cur);
    }
    
    return answer;
}
