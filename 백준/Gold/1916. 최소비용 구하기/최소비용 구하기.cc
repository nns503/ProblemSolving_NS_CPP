#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int INF = 100000000;
vector<pair<int, int>> adj[100001];
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;
int st, ed;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;	
	while(m--){
		int a, b, c; 
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	cin >> st >> ed;
	
	fill(dist, dist+n+1, INF);
	pq.push({0, st});
	dist[st] = 0;
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(dist[cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(dist[cur.Y] + nxt.X >= dist[nxt.Y]) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({dist[nxt.Y], nxt.Y});  
		}
	}
	
	cout << dist[ed];
	
	return 0;
}