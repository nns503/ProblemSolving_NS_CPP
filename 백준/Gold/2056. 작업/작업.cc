#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<int> adj[10001];
int t[10001];
int deg[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> t[i];
		int a;
		cin >> a;
		deg[i] = a;
		if(a == 0) pq.push({t[i], i});
		while(a--){
			int b;
			cin >> b;
			adj[b].push_back(i);
		}
	}
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		answer = cur.X;
		for(int i=0; i<adj[cur.Y].size(); i++){
			int nxt = adj[cur.Y][i];
			deg[nxt]--;
			if(deg[nxt] == 0){
				pq.push({cur.X + t[nxt], nxt});
			}
		}
	}
	
	cout << answer;
	return 0;
}