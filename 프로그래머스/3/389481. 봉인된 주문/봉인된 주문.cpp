#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    if(a.size() == b.size()){
        return a <= b;
    }
    return a.size() < b.size();
}

string getStr(long long n){
    string str;
    while(n > 0){
        n--;
        char c = 'a' + (n % 26);
        str = c + str;
        n /= 26;
    }
    return str;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    string str = getStr(n);
    sort(bans.begin(), bans.end(), cmp);
    
    int index = 0;
    for(int i=0; i<bans.size(); i++){
        auto cur = bans[i];
        if(!cmp(cur, str)){
            break;
        }
        index++;
        str = getStr(n + index);
    }
    
    return str;
}