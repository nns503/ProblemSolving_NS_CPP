#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dist[101][101];
int n, m;
const int INF = 200000000;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		fill(dist[i], dist[i]+n+1, INF);
	}
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for(int i=1; i<=n; i++) dist[i][i] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
			}
		} 
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}	
	return 0;
}