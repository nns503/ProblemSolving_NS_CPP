#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];
int cp[100001];

void DFS(int cur, int prev){
	for(int c : adj[cur]){
		if(c == prev) continue;
		cp[c] += cp[cur];
		DFS(c, cur);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		int a; 
		cin >> a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		cp[a] += b;
	}
	
	DFS(1, -1); 
	
	for(int i=1; i<=n; i++){
		cout << cp[i] << ' ';
	}
	return 0;
}