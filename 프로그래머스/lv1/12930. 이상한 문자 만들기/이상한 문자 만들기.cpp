#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ') cnt = 0;
        else{
            if(cnt % 2) s[i] = tolower(s[i]);
            else s[i] = toupper(s[i]);
            cnt++;
        }
    }
    return s;
}