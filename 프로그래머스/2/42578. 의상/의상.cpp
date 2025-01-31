#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++; 
    }
    for(auto &cur : m){
        cout << m[cur.first] + 1 << '\n';
        answer *= (m[cur.first] + 1);
    }
    return answer - 1;
}