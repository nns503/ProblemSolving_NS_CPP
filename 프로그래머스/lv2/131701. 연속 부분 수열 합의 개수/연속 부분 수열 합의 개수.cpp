#include <bits/stdc++.h>

using namespace std;

unordered_set<int> us;

int solution(vector<int> elements) {
    int answer = 0;
    for(int i=0; i<elements.size(); i++){
        int a = 0;
        for(int j=i; j<elements.size() + i; j++){
            a += elements[j % elements.size()];
            us.insert(a);
        }
    }
    return us.size();
}