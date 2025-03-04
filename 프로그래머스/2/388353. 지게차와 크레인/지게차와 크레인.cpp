#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(vector<vector<int>> &vis, int y, int x){
    if(y < 0 || x < 0 || y >= vis.size() || x >= vis[y].size()){
        return true;
    }
    if(vis[y][x] == 2) return true;
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = storage.size() * storage[0].size();
    vector<vector<int>> vis(
        storage.size(), 
        vector<int>(storage[0].size(), 0));
    
    for(auto req : requests){
        
        if(req.size() == 1){
            for(int y=0; y<storage.size(); y++){
                for(int x=0; x<storage[y].size(); x++){
                    if(vis[y][x] != 0) continue;
                    if(storage[y][x] == req[0]){
                        for(int i=0; i<4; i++){
                            int ny = y + dy[i];
                            int nx = x + dx[i];
                            if(OOB(vis, ny, nx)){
                                vis[y][x] = 1;
                                answer--;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        if(req.size() == 2){
            for(int y=0; y<storage.size(); y++){
                for(int x=0; x<storage[y].size(); x++){
                    if(vis[y][x] != 0) continue;
                    if(storage[y][x] == req[0]){
                        vis[y][x] = 1;
                        answer--;
                    }
                }
            }
        }
        
        int a = 50;
        while(a--){
        for(int y=0; y<storage.size(); y++){
            for(int x=0; x<storage[y].size(); x++){
                if(vis[y][x] == 1){
                    for(int i=0; i<4; i++){
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if(OOB(vis, ny, nx)){
                            vis[y][x] = 2;
                            break;
                        }
                    }
                }
            }
        }
        }
    }
    
    return answer;
}