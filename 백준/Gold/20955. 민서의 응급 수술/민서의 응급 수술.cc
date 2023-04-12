#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];
int cnt;
int answer;

void DFS(int cur, int prev){
	for(auto c : adj[cur]){
		if(c == prev) continue;
		if(vis[c]){
			cnt++;
			continue; 
		}
		vis[c] = true;
		DFS(c, cur);
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		cnt = 0;
		vis[i] = true;
		DFS(i, -1);
		answer += 1 + cnt/2;
	}
	
	cout << answer - 1 ;
	return 0;
}