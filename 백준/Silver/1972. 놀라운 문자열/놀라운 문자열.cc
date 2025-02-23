#include <bits/stdc++.h>

using namespace std;

bool solve(string word){
    for(int d=1; d<=word.size()-1; d++){
        set<string> s;
        for(int i=0; i<word.size()-d; i++){
            string str;
            str += word[i];
            str += word[i+d];
            s.insert(str);
        }
        if(s.size() != word.size() - d) return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while(true){
        cin >> str;
        if(str == "*") break;
        if(solve(str)){
            cout << str << " is surprising.\n";
        }
        else{
            cout << str << " is NOT surprising.\n";
        }
    }
    return 0;
}