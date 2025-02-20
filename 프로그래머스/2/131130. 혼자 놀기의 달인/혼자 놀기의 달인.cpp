#include <bits/stdc++.h>

using namespace std;

int p[101];
int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(p[a] == p[b]) return;
    if(a < b) p[b] = a;
    else p[a] = b;
}

int solution(vector<int> cards) {
    int answer = 0;
    for(int i=1; i<=cards.size(); i++){
        p[i] = i;
    }
    
    for(int i=0; i<cards.size(); i++){
        uni(i+1, cards[i]);
    }
    
    map<int, int> num;
    for(int i=1; i<=cards.size(); i++){
        num[find(p[i])]++;
    }
    
    vector<int> arr;
    arr.push_back(0);
    for(auto cur : num){
        arr.push_back(cur.second);
    }
    sort(arr.begin(), arr.end(), greater<>());
    
    return arr[0] * arr[1];
}