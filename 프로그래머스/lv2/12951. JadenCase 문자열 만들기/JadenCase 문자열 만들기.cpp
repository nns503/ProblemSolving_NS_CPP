#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    bool a = true;
    for(int i=0; i<s.size(); i++){
        if(a){
            s[i] = toupper(s[i]);
            a = false;
        }
        else{
            s[i] = tolower(s[i]);
        }
        if(s[i] == ' ') a = true;
    }
    return s;
}