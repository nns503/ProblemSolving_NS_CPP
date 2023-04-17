#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
vector<pair<int, int>> adj[10001]; // 번호, 가중치 
int dp[10001];
vector<int> v;
int mn;
int node;

void DFS(int cur, int prev){
	for(auto nxt : adj[cur]){
		if(nxt.X == prev) continue;
		dp[nxt.X] += nxt.Y + dp[cur];
		DFS(nxt.X, cur);
	}
}

int main(void){
	cin >> n;
	
	int t = n-1;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	DFS(1, 0);
	
	for(int i=1; i<=n; i++){
		if(dp[i] > mn){
			mn = dp[i];
			node = i;
		}
	}
	
	fill(dp, dp+n+1, 0);
	DFS(node, 0);
	cout << *max_element(dp, dp+n+1);

	return 0;
}