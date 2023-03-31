#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v1[100];
vector<int> v2[100];
bool vis[100];
int w1[100];
int w2[100];

void dfs1(int cur){
	vis[cur] = true;
	w1[cur]++;
	for(auto nx : v1[cur]){
		if(vis[nx]) continue;
		dfs1(nx);
	}
}

void dfs2(int cur){
	vis[cur] = true;
	w2[cur]++;
	for(auto nx : v2[cur]){
		if(vis[nx]) continue;
		dfs2(nx);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;	
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		fill(vis, vis+n+1, false);
		dfs1(i);
		dfs2(i);
	}
	
	int answer = 0;

	for(int i=1; i<=n; i++){
		if(w1[i] > (n+1)/2 || w2[i] > (n+1)/2 ) answer++;
	}
	
	cout << answer;
	return 0;
}