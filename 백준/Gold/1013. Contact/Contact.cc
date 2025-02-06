#include <bits/stdc++.h>

using namespace std;

// 100+1+
int PatternOne(string str, int st){
    if(str.size() - st < 4) return -1;
    if(str.substr(st, 3) != "100" ) return -1;
    int p = st+3;
    for(; p<str.size(); p++){
        if(str[p] != '0') break;
    }

    if(p >= str.size()) return -1;
    if(str[p] != '1') return -1;

    return p+1;
}

// 01
int PatternTwo(string str, int st){
    if(str.size() - st < 2) return -1;
    if(str.substr(st, 2) != "01") return -1;
    return st + 2;
}

bool solve(string str){

    int i = 0;
    bool flag = false;
    while(i < str.size()){
        if(str[i] == '1'){
            int temp = PatternOne(str, i);
            if(temp == -1 && flag == false) return false;
            if(temp == -1) i++;
            else i = temp;
            flag = true;
        }
        if(str[i] == '0'){
            i = PatternTwo(str, i);
            if(i == -1) return false;
            flag = false;
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        string str; cin >> str;
        if(solve(str)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}