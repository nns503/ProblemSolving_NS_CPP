#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<int> adj[100001];
int p[100001];
int subnode[100001];


void DFS(int cur, int prev){
	for(int nxt : adj[cur]){
		if(nxt == prev) continue;
		p[nxt] = cur;
		DFS(nxt, cur);
	}
}

void countSubtreeNodes(int cur){
	subnode[cur] = 1;
	for(int node : adj[cur]){
		if(node == p[cur]) continue;
		countSubtreeNodes(node);
		subnode[cur] += subnode[node];
	}	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r >> q;
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	DFS(r, -1);
	countSubtreeNodes(r);
	
	for(int i=0; i<q; i++){
		int a;
		cin >> a;
		cout << subnode[a] << '\n';
	}
	return 0;
}