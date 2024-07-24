#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int num = 0;
    for(int i=0;i<str.size();){
        num++;
        string cur = to_string(num);
        for(int k=0; k<cur.size(); k++){
            if(i >= str.size()) break;
            if(cur[k] == str[i]) i++;
        }
    }

    cout << num;

}