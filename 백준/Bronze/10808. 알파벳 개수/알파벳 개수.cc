#include <bits/stdc++.h>

using namespace std;

int alphabet[26];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(char a:s){
        alphabet[a-'a']++;
    } 
    for(int a:alphabet){
        cout << a << " ";
    }
}