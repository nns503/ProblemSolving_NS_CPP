#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v[20001];
int dist[20001];
vector<pair<int, int>> res;
queue<int> Q;

bool cmp(pair<int, int> p1, pair<int ,int> p2){
	if(p1.first == p2.first) return p1.second < p2.second;	
	return p1.first > p2.first;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	fill(dist, dist+n+1, -1);
	Q.push(1);
	dist[1] = 0;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int i=0; i<v[cur].size(); i++){
			int nx = v[cur][i];
			if(dist[nx] != -1) continue;
			Q.push(nx);
			dist[nx] = dist[cur] + 1;
		}
	}
	
	for(int i=1; i<=n; i++){
		res.push_back({dist[i], i});
	}
	
	sort(res.begin(), res.end(), cmp);
	
	int cnt = 1;
	for(int i=1; i<=n; i++){
		if(res[i-1].first != res[i].first) break;
		cnt ++;
	}
	cout << res[0].second << ' '  << res[0].first << ' ' << cnt;
	return 0;
}