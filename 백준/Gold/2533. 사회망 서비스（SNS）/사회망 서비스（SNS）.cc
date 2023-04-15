#include <bits/stdc++.h>

using namespace std;

int n, u, v, answer;
vector<int> adj[1000001];
int dp[1000001];
bool al[1000001];

int DFS(int cur, int prev){
	for(int nxt : adj[cur]){
		if(nxt == prev) continue;
		dp[cur] += DFS(nxt, cur);
	}
	if(al[cur] == false && al[prev] == false){
		al[prev] = true;
		dp[cur]++;
	}
	return dp[cur];
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	al[0] = true;
	
	
	cout << DFS(1, 0);
	
	return 0;
}