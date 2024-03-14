#include <bits/stdc++.h>

using namespace std;

int board[101][101];

vector<int> solution(int r, int c, vector<vector<int>> queries) {
    vector<int> answer;
    int number = 1;
    for(int y=1; y<=r; y++){
        for(int x=1; x<=c; x++){
            board[y][x] = number;
            number++;
        }
    }

    
    for(int i=0; i<queries.size(); i++){
        int y1 = queries[i][0]; int x1 = queries[i][1];
        int y2 = queries[i][2]; int x2 = queries[i][3];
        
        int mn = 0x3f3f3f3f;
        vector<int> arr;
        
        for(int x = x1; x < x2; x++) arr.push_back(board[y1][x]);
        for(int y = y1; y < y2; y++) arr.push_back(board[y][x2]);
        for(int x = x2; x > x1; x--) arr.push_back(board[y2][x]);
        for(int y = y2; y > y1; y--) arr.push_back(board[y][x1]);
        
        for(auto cur : arr){
            mn = min(cur, mn);
        }
        int index = 0;
        for(int x = x1+1; x < x2; x++){
            board[y1][x] = arr[index]; index++;
        }
        for(int y = y1; y < y2; y++){
            board[y][x2] = arr[index]; index++;
        }
        for(int x = x2; x > x1; x--){
            board[y2][x] = arr[index]; index++;
        }
        for(int y = y2; y > y1; y--){
            board[y][x1] = arr[index]; index++;
        }
        board[y1][x1] = arr[index];
        answer.push_back(mn);
    }
    return answer;
}