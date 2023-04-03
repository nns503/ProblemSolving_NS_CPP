#include <bits/stdc++.h>

using namespace std;

string t[4] = {"aya", "woo", "ye", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(auto s : babbling){
        string prev = "";
        for(int i=0; i<=s.size(); ){
            if(i == s.size()){
                answer++;
                break;
            }
            if(s.size() - i >= 2){
                string a = s.substr(i, 2);
                if((a == t[2] || a == t[3]) && a != prev){
                    i += 2;
                    prev = a;
                    continue;
                }
            }
            if(s.size() - i >= 3){
                string a = s.substr(i, 3);
                if((a == t[0] || a == t[1]) && a!= prev){
                    i += 3;
                    prev = a;
                    continue;
                }
            }
            break;
        }
    }
    return answer;
}