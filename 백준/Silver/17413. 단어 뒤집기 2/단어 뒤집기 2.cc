#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    bool flag = false;
    int st = 0;
    for(int i=0; i<str.size(); i++){
        auto cur = str[i];
        if(cur == '<'){
            reverse(str.begin() + st, str.begin() + i);
            flag = true;
            continue;
        }
        if(cur == '>'){
            flag = false;
            st = i+1;
            continue;
        }
        if(flag) continue;
        if(cur == ' '){
            reverse(str.begin() + st, str.begin() + i);
            st = i+1;
        }
        if(i == str.size() - 1){
            reverse(str.begin() + st, str.end());
        }
    }

    cout << str;
    return 0;
}