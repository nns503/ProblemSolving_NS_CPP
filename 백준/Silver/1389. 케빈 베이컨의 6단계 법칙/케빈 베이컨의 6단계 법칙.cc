#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> fr[101];
int mn = 10000;
int answer;
int dist[101];
queue<int> Q;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		fill(dist, dist+101, -1); 
		Q.push(i);
		int kb = 0;
		dist[i] = 0;
		while(!Q.empty()){
			int cur = Q.front(); Q.pop();
			for(int k=0; k<fr[cur].size(); k++){
				int nt = fr[cur][k];
				if(dist[nt] != -1) continue;
				dist[nt] = dist[cur] + 1;
				Q.push(nt);
			}
		}
		for(int t=1; t<=n; t++) kb += dist[t];
		if(mn > kb) {
			mn = kb;
			answer = i; 
		}
	}
	
	cout << answer;
	
	return 0;
}
