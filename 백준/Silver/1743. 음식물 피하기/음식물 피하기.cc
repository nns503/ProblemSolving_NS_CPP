#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, k;
int board[101][101];
bool vis[101][101];
int answer;
queue<pair<int, int>> q;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OOB(int y, int x){
	return (y <= 0 || x <= 0 || y > n || x > m);
}

int BFS(int y, int x){
	int cnt = 1;
	q.push({y, x});
	vis[y][x] = true;
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == 0) continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = true;
			cnt++;
			q.push({ny, nx});
		}
	}	
	
	return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	
	for(int i=0; i<k; i++){
		int y, x;
		cin >> y >> x;
		board[y][x] = 1;
	}
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			if(board[y][x] == 0) continue;
			if(vis[y][x]) continue;
			answer = max(BFS(y, x), answer);
		}
	}
	
	cout << answer;
	
		
	
	return 0;
}