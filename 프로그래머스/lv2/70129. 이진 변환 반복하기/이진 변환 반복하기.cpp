#include <bits/stdc++.h>
using namespace std;
vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0;
    int cnt = 0;
    while(s != "1"){
        cnt++;
        int len = 0;
        string temp = ""; 
        for(char c : s){
            if(c == '1') len++;
            else zero++;
        }
        while(len > 0){
            temp += to_string(len % 2);
            len /= 2;
        }
        reverse(temp.begin(), temp.end());
        s = temp;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}