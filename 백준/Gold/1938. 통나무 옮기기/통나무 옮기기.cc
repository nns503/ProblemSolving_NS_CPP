#include <bits/stdc++.h>

using namespace std;

int n;
string board[51];
int dist[51][51][2]; // 0 -> 가로, 1-> 세로 && 중심점 기준 
int dy[4] = {-1, 1, 0, 0}; 
int dx[4] = {0, 0, -1, 1};
queue<tuple<int, int, int>> q;
int py, px, pt;

bool OOB_H(int y, int x){
	return (y < 1 || x < 0 || y >= n-1 || x >= n);
}

bool OOB_W(int y, int x){
	return (y < 0 || x < 1 || y >= n || x >= n-1);
}

bool chk(int y, int x){
	if(y < 1 || x < 1 || y >= n-1 || x >= n-1) return true;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(board[y+i][x+j] == '1') return true;
		}
	}
	return false;
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> board[i];
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			dist[y][x][0] = -1;
			dist[y][x][1] = -1;
		}
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			if(!OOB_H(y, x)){
				if(board[y][x] == 'B' && board[y+1][x] == 'B' && board[y-1][x] == 'B'){
					q.push(make_tuple(y, x, 1));
					dist[y][x][1] = 0;
				}
				if(board[y][x] == 'E' && board[y+1][x] == 'E' && board[y-1][x] == 'E'){
					py = y; px = x; pt = 1;
				}
			}
			
			if(!OOB_W(y, x)){
				if(board[y][x] == 'B' && board[y][x+1] == 'B' && board[y][x-1] == 'B'){
					q.push(make_tuple(y, x, 0));
					dist[y][x][0] = 0;
				}
				if(board[y][x] == 'E' && board[y][x+1] == 'E' && board[y][x-1] == 'E'){
					py = y; px = x; pt = 0;
				}
			}
		}
	}
	
	while(!q.empty()){
		int y, x, t;
		tie(y, x, t) = q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(t==0){
				if(OOB_W(ny, nx)) continue;
				if(dist[ny][nx][0] != -1) continue;
				if(board[ny][nx-1] == '1' || board[ny][nx] == '1' || board[ny][nx+1] == '1') continue;
			}
			else if(t==1){
				if(OOB_H(ny, nx)) continue;
				if(dist[ny][nx][1] != -1) continue;
				if(board[ny-1][nx] == '1' || board[ny][nx] == '1' || board[ny+1][nx] == '1') continue;
			}
			q.push(make_tuple(ny, nx, t));
			dist[ny][nx][t] = dist[y][x][t] + 1;
		}
	
		if(chk(y, x)) continue;
		if(dist[y][x][1-t] != -1) continue;
		q.push(make_tuple(y, x, 1-t));
		dist[y][x][1-t] = dist[y][x][t] + 1;
	}
	

	if(dist[py][px][pt] == -1) cout << 0;
	else cout << dist[py][px][pt]; 
	
	return 0;
}