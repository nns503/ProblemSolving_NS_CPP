#include <bits/stdc++.h>

using namespace std;

bool checkAlp(char c){
    return (c >= 'a' && c <='z');
}

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> a;
    multiset<string> b;
    
    for(int i=0; i<str1.size()-1; i++){
        char cur = tolower(str1[i]);
        char nxt = tolower(str1[i+1]);
        if(!checkAlp(cur) || !checkAlp(nxt)) continue;
        string s;
        s.push_back(cur);
        s.push_back(nxt);
        a.insert(s);
    }
    
    for(int i=0; i<str2.size()-1; i++){
        char cur = tolower(str2[i]);
        char nxt = tolower(str2[i+1]);
        if(!checkAlp(cur) || !checkAlp(nxt)) continue;
        string s;
        s.push_back(cur);
        s.push_back(nxt);
        b.insert(s);
    }
    
    double cnt1 = 0;
    double cnt2 = 0;
    
    for(auto cur : a){
        if(b.find(cur) != b.end()){
            auto x = b.find(cur);
            cnt1++;
            b.erase(x);
        }
        cnt2++;
    }
    cnt2 += b.size();
    if(cnt2 == 0){
        return 65536;
    }
    cout << cnt1 << ' ' << cnt2;
    answer = cnt1* 65536/cnt2;
    
    return answer;
}