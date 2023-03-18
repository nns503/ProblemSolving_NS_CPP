#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string A = "김서방은 ";
    string B = "에 있다";
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i] == "Kim") {
            answer = A + to_string(i) + B;
        }
    }
    return answer;
}