#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int r, c;
int o, v;
string board[251];
bool vis[251][251];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> Q;

bool OOB(int y, int x){
	return (y >= r || x >= c || y < 0 || x < 0); 
}

void BFS(int y, int x){
	int to = 0;
	int tv = 0;
	Q.push({y, x});
	vis[y][x] = true;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		if(board[cur.Y][cur.X] == 'o') to++;
		else if(board[cur.Y][cur.X] == 'v') tv++;		
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] == '#') continue;
			if(vis[ny][nx]) continue;
			vis[ny][nx] = true;
			Q.push({ny, nx});
		}
	}
	if(to > tv) o += to;
	else v += tv;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	
	for(int i=0; i<r; i++){
		cin >> board[i];
	}
	
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(vis[y][x] || board[y][x] == '#') continue;
			BFS(y, x);
		}
	}
	
	cout << o << ' ' << v;

	return 0;
}