#include <bits/stdc++.h>
#define T first
#define N second

using namespace std;

int n, d, c;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> d >> c;
        vector<pair<int, int>> edge[n + 1];
        vector<int> dist(n+1, 0x3f3f3f3f);
        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            edge[b].push_back({s, a});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

    
        dist[c] = 0;
        pq.push({0, c});

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(dist[cur.N] != cur.T) continue;
            for(auto nxt : edge[cur.N]){
                if(dist[nxt.N] > dist[cur.N] + nxt.T){
                    pq.push({dist[cur.N] + nxt.T, nxt.N});
                    dist[nxt.N] = dist[cur.N] + nxt.T;
                }
            }
        }

        int count = 0;
        int time = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 0x3f3f3f3f) continue;
            count++;
            time = max(time, dist[i]);
        }

        cout << count << ' ' << time << '\n';
    }

    return 0;
}