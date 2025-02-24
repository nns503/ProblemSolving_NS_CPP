#include <bits/stdc++.h>

using namespace std;

int p[201];

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(a < b) p[b] = a;
    else p[a] = b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        p[i] = i;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j] == 1) uni(i, j);
        }
    }
    
    set<int> ans;
    for(int i=0; i<n; i++){
        ans.insert(find(i));
    }
    
    return ans.size();
}

// 5:10