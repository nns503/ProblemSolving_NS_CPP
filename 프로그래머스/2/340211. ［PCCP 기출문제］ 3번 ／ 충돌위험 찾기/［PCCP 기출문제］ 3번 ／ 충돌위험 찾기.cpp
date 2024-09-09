#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<pair<int, int>> p;
    p.push_back({0, 0});
    for(int i=0; i<points.size(); i++){
        p.push_back({points[i][0], points[i][1]});
    }
    vector<int> index(routes.size()+2, 1);
    vector<vector<int>> board(101, vector<int>(101, 0));
    vector<pair<int, int>> x;
    
    for(int i=0; i<routes.size(); i++){
        auto cur = p[routes[i][0]];
        x.push_back({cur.Y, cur.X});
        board[cur.Y][cur.X]++;
    }
    
    int cnt = 0;
    int answer = 0;
    for(int y=1; y<=100; y++){
        for(int x=1; x<=100; x++){
            if(board[y][x] >= 2){
                answer++;
            }
        }
    }
    while(cnt < routes.size()){
        for(int i=0; i<routes.size(); i++){
            int curIndex = index[i];
            if(curIndex > routes[i].size()) continue;
            if(curIndex == routes[i].size()){
                cnt++;
                auto cur = x[i];
                board[cur.Y][cur.X]--;
                index[i]++;
                continue;
            }
            
            auto nxt = p[routes[i][curIndex]];
            auto cur = x[i];
            board[cur.Y][cur.X]--;
            
            if(nxt.Y != cur.Y){
                if(nxt.Y < cur.Y) cur.Y--;
                else cur.Y++;
            }
            else{
                if(nxt.X < cur.X) cur.X--;
                else cur.X++;
            }
            
            board[cur.Y][cur.X]++;
            x[i] = cur;
            if(nxt == cur) index[i]++;
        }
        
        for(int y=1; y<=100; y++){
            for(int x=1; x<=100; x++){
                if(board[y][x] >= 2){
                    answer++;
                }
            }
        }
    }
    
    return answer;
}