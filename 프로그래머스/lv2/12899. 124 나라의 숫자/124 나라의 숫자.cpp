#include <bits/stdc++.h>

using namespace std;

char d[3] = {'1', '2', '4'};
string solution(int n) {
    string answer = "";
    while(n > 0){
        n--;
        answer.push_back(d[n%3]);
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}