#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int d[50001];
vector<pair<int, int>> adj[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	fill(d, d+n+1, 500000001);
	
	for(int i=0; i<m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	
	d[1] = 0;
	pq.push({0, 1});
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(cur.X != d[cur.Y]) continue;
		for(auto nxt : adj[cur.Y]){
			if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({d[nxt.Y], nxt.Y});
		}
	}
	
	cout << d[n];
	return 0;
}