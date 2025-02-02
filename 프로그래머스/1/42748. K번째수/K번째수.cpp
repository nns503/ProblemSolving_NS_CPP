#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> temp(array);
        int st = commands[i][0] - 1;
        int en = commands[i][1];
        int k = commands[i][2] - 1;
        sort(temp.begin() + st, temp.begin() + en);
        answer.push_back(temp[st + k]);
    }
    return answer;
}