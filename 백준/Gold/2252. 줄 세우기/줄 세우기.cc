#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[32001];
int deg[32001];
queue<int> Q;
vector<int> line;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	while(m--){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	
	for(int i=1; i<=n; i++){
		if(deg[i] == 0) Q.push(i);
	}
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		line.push_back(cur);
		for(int nxt : adj[cur]){
			deg[nxt]--;
			if(deg[nxt] == 0) Q.push(nxt);
		}
	}
	
	for(int a : line){
		cout << a << ' ';
	}
	
	return 0;
}