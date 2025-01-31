#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    for(auto cur : phone_book){
        s.insert(cur);
    }
    for(auto cur : phone_book){
        for(int i=0; i<cur.size()-1; i++){
            string str = cur.substr(0, i+1);
            if(s.find(str) != s.end()) return false;
        }
    }
    return true;
}