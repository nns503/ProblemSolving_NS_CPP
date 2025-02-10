#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &p, int x){
    if(p[x] == x) return x;
    return p[x] = find(p, p[x]);
}

void uni(vector<int> &p, int a, int b){
    a = find(p, a);
    b = find(p, b);
    p[a] = b;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0x3f3f3f3f;
    
    for(int i=0; i<wires.size(); i++){
        vector<int> p(n+1, 0);
        for(int j=1; j<=n; j++) p[j] = j;
        for(int j=0; j<wires.size(); j++){
            if(i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            uni(p, a, b);
        }
        map<int, int> m;
        for(int j=1; j<=n; j++){
            m[find(p, p[j])]++;
        }
        vector<int> temp;
        for(auto cur : m){
            temp.push_back(cur.second);
        }
        cout << i << " => " << abs(temp[0] - temp[1]) << ' ' << m.size() << '\n';
        answer = min(answer, abs(temp[0] - temp[1]));
    }
    
    return answer;
}