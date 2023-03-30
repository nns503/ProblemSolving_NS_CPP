#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int y1 = arr1.size();
    int x1 = arr1[0].size();
    int y2 = arr2.size();
    int x2 = arr2[0].size();
    for(int y=0; y<y1; y++){
        vector<int> v;
        for(int xx=0; xx<x2; xx++){
            int temp = 0;
            for(int x=0; x<x1; x++){
                temp += arr1[y][x] * arr2[x][xx];
            }
            v.push_back(temp);
        }
        answer.push_back(v);
    }
    return answer;
}

