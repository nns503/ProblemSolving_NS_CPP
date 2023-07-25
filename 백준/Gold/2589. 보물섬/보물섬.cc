#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int l, w;
int answer;
string board[51];
bool vis[51][51];
int dist[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

bool OOB(int y, int x){
	return (y<0 || x<0 || y>=l || x>=w);
}

void setDist(){
	for(int i=0; i<l; i++){
		for(int j=0; j<w; j++){
			dist[i][j] = -1;
		}
	}
}

int getLen(int y, int x){
	setDist();
	dist[y][x] = 0;
	q.push({y, x});
	int len = 0;
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] != 'L') continue;
			if(dist[ny][nx] != -1) continue;
			q.push({ny, nx});
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
			len = max(len, dist[ny][nx]);
		}
	}
	
	return len;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> w;
	
	for(int i=0; i<l; i++){
		cin >> board[i];
	}
		
	for(int i=0; i<l; i++){
		for(int j=0; j<w; j++){
			if(board[i][j] == 'W') continue;
			answer = max(answer, getLen(i, j));
		}
	}
	
	
	cout << answer;
}