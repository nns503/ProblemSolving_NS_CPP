#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0; i<name.size(); i++){
        m[name[i]] = yearning[i]; 
    }
    for(int i=0; i<photo.size(); i++){
        int temp = 0;
        for(int j=0; j<photo[i].size(); j++){
            if(m.find(photo[i][j]) != m.end()) temp += m[photo[i][j]];
        }
        answer.push_back(temp);
    }
    return answer;
}