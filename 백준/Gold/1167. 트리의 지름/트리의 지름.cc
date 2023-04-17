#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> adj[100001];
long long dp[100001];
long long mx;
int node;

void DFS(int cur, int prev){
	for(auto nxt : adj[cur]){
		if(nxt.first == prev) continue;
		dp[nxt.first] += nxt.second + dp[cur];
		DFS(nxt.first, cur);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		int v;
		cin >> v;
		while(true){
			int a, b;
			cin >> a; 
			if(a == -1) break;
			cin >> b;
			adj[v].push_back({a, b});
		}
	}
	
	for(int i=1; i<=n; i++){
		if(adj[i].size() != 1) continue;
		DFS(i, 0);
		break;
	}
	
	for(int i=1; i<=n; i++){
		if(mx < dp[i]){
			mx = dp[i];
			node = i; 
		}
	}
	
	fill(dp, dp+n+1, 0);
	DFS(node, 0);
	
	cout << *max_element(dp, dp+n+1);
	
	
	return 0;
}