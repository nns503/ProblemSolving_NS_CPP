#include <bits/stdc++.h>

using namespace std;

int a;
bool cmp(string s1, string s2){
    if(s1[a] == s2[a]) return s1 < s2;
    return s1[a] < s2[a];
}
vector<string> solution(vector<string> strings, int n) {
    a = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}