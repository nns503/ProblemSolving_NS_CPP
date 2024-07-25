#include <bits/stdc++.h>

using namespace std;

int answer = 0;
map<char, int> m;

bool chk(char prv){
    if(m[prv] <= 0){
        answer = -1;
        return false;
    }
    m[prv]--;
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int temp = 0;
    for(auto cur : str){
        if(cur == 'q'){
            m[cur]++;
            temp++;
            answer = max(temp, answer);
        }
        else if(cur == 'u'){
            if(!chk('q')) break;
            m[cur]++;
        }
        else if(cur == 'a'){
            if(!chk('u')) break;
            m[cur]++;
        }
        else if(cur == 'c'){
            if(!chk('a')) break;
            m[cur]++;
        }
        else if(cur == 'k'){
            if(!chk('c')) break;
            temp--;
        }
    }

    if(m['q'] != 0 || m['u'] != 0 || m['a'] != 0 || m['c'] != 0){
        answer = -1;
    }
    cout << answer;

    return 0;
}