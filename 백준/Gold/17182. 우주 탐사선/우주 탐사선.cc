#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, k;
int d[11][11];
int answer = 0x3f3f3f3f;
bool vis[11];

void DFS(int num, int sum, int prv){
    if(num == n){
        answer = min(answer, sum);
    }

    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        DFS(num+1, sum+d[prv][i], i);
        vis[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio;
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++) fill(d[i], d[i]+n, INF);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vis[k] = true;
    DFS(1, 0, k);

    cout << answer;

    return 0;
}