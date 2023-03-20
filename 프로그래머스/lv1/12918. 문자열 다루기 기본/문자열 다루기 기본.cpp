#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    if(s.size() == 4 || s.size() == 6){
        for(char a : s){
            if(a < '0' || a > '9') return false;
        }
        return true;
    }
    return false;
}