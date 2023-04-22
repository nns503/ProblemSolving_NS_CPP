#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int v, e;
bool chk[10001];
vector<pair<int ,int>> adj[100001];
int cnt;
int answer;
priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	while(e--){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	
	chk[1] = true;
	for(auto a : adj[1]) pq.push({a.X, a.Y});
	
	while(cnt < v-1){
		auto cur = pq.top(); pq.pop();
		if(chk[cur.Y]) continue;
		answer += cur.X;
		cnt++;
		chk[cur.Y] = true;
		for(auto nxt : adj[cur.Y]){
			if(chk[nxt.Y]) continue;
			pq.push(nxt);
		}
	}
	
	cout << answer;
	
	return 0;
}