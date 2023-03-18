#include <bits/stdc++.h>

using namespace std;

bool solution(int x) {
    string s = to_string(x);
    int sum = 0;
    for(char a : s){
        sum += a - '0';
    }
    return !(x%sum);
}