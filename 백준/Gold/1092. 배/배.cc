#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int box[10001];
int dist[10001];
int crane[51];
int d[51];
queue<pair<int, int>> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> crane[i];
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> box[i];
    }

    sort(crane, crane+n);
    sort(box, box+m);

    fill(d, d+n, m-1);
    fill(dist, dist+m, -1);
    
    for(int i=0; i<n; i++){
        q.push({i, 1});
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        while(true){
            if(d[cur.X] < 0) break;
            if(crane[cur.X] < box[d[cur.X]] || dist[d[cur.X]] != -1){
                d[cur.X]--;
            }
            else if(crane[cur.X] >= box[d[cur.X]]) break;
        }  
        if(d[cur.X] < 0) continue;
        dist[d[cur.X]] = cur.Y;
        q.push({cur.X, cur.Y+1});
    } 

    int answer = 0;
    for(int i=0; i<m; i++){
        if(dist[i] == -1){
            cout << -1;
            return 0;
        }
        else answer = max(answer, dist[i]);
    }

    cout << answer;
    return 0;
}