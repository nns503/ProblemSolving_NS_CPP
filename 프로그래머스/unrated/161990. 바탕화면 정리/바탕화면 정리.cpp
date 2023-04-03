#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

vector<pair<int, int>> v;
int max_x = 0, max_y = 0;
int min_x = 51, min_y = 51;

vector<int> solution(vector<string> wallpaper) {
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[0].size(); j++){
            if(wallpaper[i][j] == '#') v.push_back({i, j});
        }
    }
    for(auto a : v){
        cout << a.X << ' ' << a.Y << '\n';
        min_x = min(min_x, a.X);
        min_y = min(min_y, a.Y);
        max_x = max(max_x, a.X+1);
        max_y = max(max_y, a.Y+1);
    }
    return {min_y, min_x, max_y, max_x};
}