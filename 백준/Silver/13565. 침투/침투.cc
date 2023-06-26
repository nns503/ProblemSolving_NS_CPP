#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int m, n;
string board[1001];
bool vis[1001][1001];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> Q;

bool OOB(int y, int x){
	return (y >= m || x >= n || y < 0 || x < 0); 
}

void BFS(int y, int x){
	Q.push({y, x});
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == '1') continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = true;
			Q.push({ny, nx});
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	
	for(int i=0; i<m; i++){
		cin >> board[i];
	}
	
	for(int x=0; x<n; x++){
		if(board[0][x] == '1') continue;
		if(vis[0][x]) continue;
		BFS(0, x);
	}
	

	for(int x=0; x<n; x++){
		if(vis[m-1][x]){
			cout << "YES";
			return 0;
		} 
	}
	
	cout << "NO";
	
	return 0;
}