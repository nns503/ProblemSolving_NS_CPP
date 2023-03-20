#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int sum = 0;
string solution(string s) {
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-'){
            i++;
            while(i != s.size() && s[i] != ' '){
                sum *= 10;
                sum += s[i] - '0';
                i++;
            }
            num.push_back(-sum);
        }
        else{
            while(i != s.size() && s[i] != ' '){
                sum *= 10;
                sum += s[i] - '0';
                i++;
            }
            num.push_back(sum);
        }
        sum = 0;
    }
    sort(num.begin(), num.end());
    string answer = to_string(num[0]) + " " + to_string(*(num.end()-1));
    return answer;
}