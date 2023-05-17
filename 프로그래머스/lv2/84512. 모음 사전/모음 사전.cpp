#include <bits/stdc++.h>

using namespace std;

char c[5] = {'A', 'E', 'I', 'O', 'U'};
map<string, int> m;
string s;
int cnt;

void func(int sz){
    if(sz == 5) return;
    for(int i=0; i<5; i++){
        cnt++;
        s.push_back(c[i]);
        m[s] = cnt;
        func(sz+1);
        s.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    func(0);
    return m[word];
}
