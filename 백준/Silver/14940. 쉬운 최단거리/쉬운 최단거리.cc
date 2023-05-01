#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int board[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> Q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
			if(board[i][j] == 1) dist[i][j] = -1;
			if(board[i][j] == 2){
				Q.push({i, j});
			}
		}
	}	
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == 0) continue;
			if(dist[ny][nx] != -1) continue;
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
			Q.push({ny, nx});
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}	
	
	
	return 0;
}