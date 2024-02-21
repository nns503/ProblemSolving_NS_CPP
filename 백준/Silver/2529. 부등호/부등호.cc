#include <bits/stdc++.h>

using namespace std;

int k;
char sign[10];
bool vis[10];
string mn = "999999999";
string mx = "0";

void func(int cnt, string str){
    if(cnt == k){
        mn = min(str, mn);
        mx = max(str, mx);
        return ;
    }

    for(int i=0; i<=9; i++){
        if(vis[i]) continue;
        if(sign[cnt] == '>'){
            if(str[cnt] - '0' < i) continue;
        } 
        if(sign[cnt] == '<'){
            if(str[cnt] - '0' > i) continue;
        }
        vis[i] = true;
        str.push_back(i + '0');
        func(cnt+1, str);
        str.pop_back();
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for(int i=0; i<k; i++) cin >> sign[i];
    for(int i=0; i<=9; i++){
        vis[i] = true;
        string str = to_string(i);
        func(0, str);
        vis[i] = false;
    }

    cout << mx << '\n' << mn;

    return 0;
}