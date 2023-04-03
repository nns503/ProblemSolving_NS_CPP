#include <bits/stdc++.h>

using namespace std;

unordered_multiset<string> s;
string solution(vector<string> participant, vector<string> completion) {
    for(auto a : participant){
        s.insert(a);
    }
    
    for(auto a : completion){
        s.erase(s.find(a));
    }
    return *s.begin();
}