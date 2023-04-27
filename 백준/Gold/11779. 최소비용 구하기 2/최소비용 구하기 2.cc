#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
int a, b;
const int INF = 1000000000;
vector<pair<int, int>> adj[100001];
int d[1001];
int pre[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int q, e, w;
		cin >> q >> e >> w;
		adj[q].push_back({w, e});
	}
	
	fill(d, d+n+1, INF);
	cin >> a >> b;
	d[a] = 0;
	pq.push({0, a});
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;	
		for(auto nxt : adj[cur.Y]){
			if(d[nxt.Y] <= nxt.X + d[cur.Y]) continue;
			d[nxt.Y] = nxt.X + d[cur.Y];
			pq.push({d[nxt.Y], nxt.Y});
			pre[nxt.Y] = cur.Y;
		}
	}
	
	cout << d[b] << '\n';
	
	vector<int> lt;
	lt.push_back(b);
	int idx = b;
	while(idx != a){
		lt.push_back(pre[idx]);
		idx = pre[idx];
	}
	reverse(lt.begin(), lt.end());
	cout << lt.size() << '\n';
	for(int nxt : lt) cout << nxt << ' ';
	return 0;
}