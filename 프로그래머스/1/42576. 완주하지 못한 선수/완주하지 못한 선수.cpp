#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for(auto cur : participant){
        m[cur]++;
    }
    for(auto cur : completion){
        m[cur]--;
    }
    for(auto cur : m){
        if(cur.second == 0) continue;
        return cur.first;
    }
    return "";
}