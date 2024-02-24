#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

vector<int> answer;
pair<int, int> board[100001];
queue<int> q;

bool isBoard(int num, int cur){
    if(board[num].A < board[cur].A + 1) return false;
    if(board[num].A == board[cur].A + 1 && board[num].B >= board[cur].B + 1) return false;
    return true;
}

bool isBoard2(int num, int cur){
    if(board[num].A < board[cur].A + 1) return false;
    if(board[num].A == board[cur].A + 1 && board[num].B >= board[cur].B) return false;
    return true;
}

vector<int> solution(int target) {
    
    for(int i=0; i<=100000; i++) board[i] = {1000000, 1000000};
    board[target] = {0, 0};
    q.push(target);
    
    
    while(!q.empty()){    
        int cur = q.front(); q.pop();
        if(cur == 0) continue;
        
        for(int i=1; i<=20; i++){
            int temp = cur - i;
            if(temp < 0) continue;
            if(!isBoard(temp, cur)) continue;
            board[temp] = {board[cur].A+1, board[cur].B+1};
            q.push(temp);
        }
        
        if(cur - 50 >= 0 && isBoard(cur-50, cur)){
            board[cur-50] = {board[cur].A+1, board[cur].B+1};
            q.push(cur-50);
        }
        
        for(int i=1; i<=20; i++){
            if(cur - i*2 >= 0 && isBoard2(cur - i*2, cur)){
                board[cur - i*2] = {board[cur].A+1, board[cur].B};
                q.push(cur - i*2);
            }
            if(cur - i*3 >= 0 && isBoard2(cur - i*3, cur)){
                board[cur - i*3] = {board[cur].A+1, board[cur].B};
                q.push(cur - i*3);
            }
        }
        
    }
    
    answer.push_back(board[0].A);
    answer.push_back(board[0].B);
    
    return answer;
}