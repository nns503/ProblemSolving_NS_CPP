#include <bits/stdc++.h>

using namespace std;

string str;
vector<int> num(101, -1);
int cnt = 0;

void solve(int st, int en){
    if(st >= en) return;
    int p = st;
    for(int i=st+1; i<en; i++){
        if(str[p] > str[i]) p = i;
    }
    num[p] = cnt++;
    solve(p+1, en);
    solve(st, p);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    solve(0, str.size());
    for(int i=0; i<str.size(); i++){
        for(int j=0; j<str.size(); j++){
            if(num[j] <= i) cout << str[j];
        }
        cout << '\n';
    }
    return 0;
}