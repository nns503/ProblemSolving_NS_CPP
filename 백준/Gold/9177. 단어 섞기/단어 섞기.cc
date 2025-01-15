#include <bits/stdc++.h>

using namespace std;

string str1, str2, target;

bool solve(int i1, int i2, string cur, set<pair<int, int>> &chk){
    if(chk.find({i1, i2}) != chk.end()) return false;
    chk.insert({i1, i2});

    if(i1 == str1.size() && i2 == str2.size()){
        return true;
    }
    bool flag = false;
    if(target[cur.size()] == str1[i1]){
        flag += solve(i1+1, i2, cur + str1[i1], chk);
    }
    if(target[cur.size()] == str2[i2]){
        flag += solve(i1, i2+1, cur + str2[i2], chk);
    }
    return flag;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        set<pair<int, int>> chk;
        cin >> str1 >> str2 >> target;
        bool flag = solve(0, 0, "", chk);
        cout << "Data set " << i << ": ";
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}