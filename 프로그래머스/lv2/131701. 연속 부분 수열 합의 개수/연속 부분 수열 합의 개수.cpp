#include <bits/stdc++.h>

using namespace std;

unordered_set<int> us;

int solution(vector<int> elements) {
    int answer = 0;
    for(int len = 1; len <= elements.size(); len++){
        for(int i=0; i<elements.size(); i++){
            int a = 0;
            for(int k = 0; k < len; k++) a += elements[(i+k) % elements.size()];
            us.insert(a);
        }
    }
    return us.size();
}