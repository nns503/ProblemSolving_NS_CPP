#include <bits/stdc++.h>

using namespace std;

set<string> pf;
bool solution(vector<string> phone_book) {
    for(auto s : phone_book) pf.insert(s);
    for(int i=0; i<phone_book.size(); i++){
        for(int len=1; len <= phone_book[i].size()-1; len++){
            string temp = phone_book[i].substr(0, len);
            if(pf.find(temp) != pf.end()) return false;
        }
    }
    return true;
}