#include <bits/stdc++.h>

using namespace std;
unordered_set<char> us;
string solution(string s, string skip, int index) {
    for(char c : skip) us.insert(c);
    for(int i=0; i<s.size(); i++){
        int t = index;
        while(t--){
            s[i]++;
            if(s[i] > 'z') s[i] = 'a';
            if(us.find(s[i]) != us.end()) t++;
        }
    }
    return s;
}