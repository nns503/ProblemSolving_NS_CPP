#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int m, n;
string temp[101];
int board[101][101];
int dist[101][101];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i=0; i<n; i++){
		cin >> temp[i];
		for(int j=0; j<m; j++){
			board[i][j] = temp[i][j] - '0';
			dist[i][j] = 1000;
		}
	}
	
	dist[0][0] = 0;
	pq.push({0, {0, 0}});
	
	while(!pq.empty()){
		int d = pq.top().Y;
		auto cur = pq.top().X;
		pq.pop(); 
		if(dist[cur.Y][cur.X] != d) continue;
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(dist[cur.Y][cur.X] + board[ny][nx] >= dist[ny][nx]) continue;
			dist[ny][nx] = dist[cur.Y][cur.X] + board[ny][nx];
			pq.push({dist[ny][nx], {ny, nx}});
		}
	}
		
	cout << dist[n-1][m-1];
	return 0;
}