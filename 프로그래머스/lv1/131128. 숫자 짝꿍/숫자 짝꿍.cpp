#include <bits/stdc++.h>

using namespace std;

multiset<char, greater<char>> ms;
multiset<char> temp;
string solution(string X, string Y) {
    string answer = "";
    for(char a : X){
        temp.insert(a);
    }
    
    for(char a : Y){
        if(temp.find(a) != temp.end()){
            ms.insert(a);
            temp.erase(temp.find(a));
        }
    }
    for(auto a : ms){
        answer += a;
    }
    if(answer[0] == '0') return "0";
    if(answer.empty()) return "-1";
    return answer;
}