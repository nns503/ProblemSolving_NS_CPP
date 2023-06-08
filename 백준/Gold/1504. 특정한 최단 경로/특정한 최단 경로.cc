#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int INF = 8000000;
int n, e, v1, v2;
vector<pair<int, int>> adj[801];
bool chk[801];
int d[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int func(int st, int en){
	fill(d, d+801, INF);
	d[st] = 0; chk[st] = true;
	
	pq.push({d[st], st});
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(nxt.X + cur.X < d[nxt.Y]){
				d[nxt.Y] = nxt.X + cur.X;
				pq.push({d[nxt.Y], nxt.Y});
			} 
		}
	}
	
	return d[en];
}

int main(void){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	cin >> n >> e;
	
	for(int i=0; i<e; i++){
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({cost, b});
		adj[b].push_back({cost, a});
	}
	
	cin >> v1 >> v2;
	
	int d1 = func(1, v1) + func(v1, v2) + func(v2, n);
	int d2 = func(1, v2) + func(v2, v1) + func(v1, n);
	int answer = min(d1, d2);
	
	cout << (answer >= INF ? -1 : answer);
		
	return 0;
}