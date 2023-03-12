#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int cnt = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=citations.front(); i>=0; i--){
        if(citations[cnt] >= i) cnt++;
        if(cnt>=i) return i;
    }
}