#include <bits/stdc++.h>

using namespace std;

int alp[27];
string str;
int answer;

void func(int prv, int cnt){
    if(str.size() == cnt){
        answer++;
        return ;
    }   

    for(int i=0; i<26; i++){
        if(alp[i] == 0) continue;
        if(prv == i) continue;
        alp[i]--;
        func(i, cnt+1);
        alp[i]++;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for(auto cur : str){
        alp[cur - 'a']++;
    }

    func(-1, 0);

    cout << answer;
    return 0;
}
