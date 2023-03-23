#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] += n;
            while(s[i] < 'a' || s[i] > 'z'){
                s[i] -= ('z' - 'a' + 1);
            }
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += n;
            while(s[i] < 'A' || s[i] > 'Z'){
                s[i] -= ('Z' - 'A' + 1);
            }
        }   
    }
    
    return s;
}