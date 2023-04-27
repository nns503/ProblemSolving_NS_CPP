#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int v, e; 
const int INF = 3000001;
vector<pair<int, int>> adj[20001];
int d[20001];
int k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	cin >> k;
	while(e--){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	
	fill(d, d+v+1, INF); 
	
	d[k] = 0;
	pq.push({0, k});
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({d[nxt.Y], nxt.Y});
		}
	}
	
	for(int i=1; i<=v; i++){
		if(d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
	
	return 0;
}