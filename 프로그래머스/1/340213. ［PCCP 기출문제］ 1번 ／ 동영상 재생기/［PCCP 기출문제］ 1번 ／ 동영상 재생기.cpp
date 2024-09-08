#include <bits/stdc++.h>

using namespace std;

int getM(string str){
    string a = str.substr(0, 2);
    int t = stoi(a);
    return t;
}

int getS(string str){
    string a = str.substr(3, 2);
    int t = stoi(a);
    return t;
}

string getTime(int t){
    string m = to_string(t / 60);
    if(m.size() == 1){
        m = "0" + m;
    }
    string s = to_string(t % 60);
    if(s.size() == 1){
        s = "0" + s;
    }
    string str = m + ":" + s;
    return str;
}

string solution(string len, string pos, string st, string en, 
                vector<string> commands) {

    int l = getM(len) * 60 + getS(len);
    int p = getM(pos) * 60 + getS(pos);
    int s = getM(st) * 60 + getS(st);
    int e = getM(en) * 60 + getS(en);
    if(p >= s && p <= e){
        p = e;
    }
    for(auto cur : commands){
        if(cur == "prev"){
            p -= 10;
            if(p < 0) p = 0;
        }
        else if(cur == "next"){
            p += 10;
            if(p > l) p = l;
        }
        
        if(p >= s && p <= e){
            p = e;
        }
        
    }
    
    string answer = getTime(p);
    return answer;
}