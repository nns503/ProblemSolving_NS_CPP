#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, answer;
tuple<int, int, int> edge[100001];
int r[1001];
int p[1001];

int find(int x){
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}

bool isSameGroup(int a, int b){
    a = find(a); 
    b = find(b);
    if(a == b) return true;
    else{
        if(p[a] == p[b]) p[a]--;
        if(p[a] < p[b]) p[b] = a;
        else p[a] = b;
        return false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<=1000; i++) p[i] = i;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = tie(c, a, b);
    }

    int cnt = 0;
    sort(edge, edge+m);

    for(int i=0; i<m; i++){
        int c, a, b;
        tie(c, a, b) = edge[i];
        if(isSameGroup(a, b)) continue;
        else{
            answer += c;
            cnt++;
        }
        if(cnt == n-1) break;
    }

    cout << answer;
    return 0;
}