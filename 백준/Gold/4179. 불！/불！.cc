#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

string board[1001];
int dist[1001][1001];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<tuple<int, int, char>> Q;
int r, c;

bool OOB(int y, int x){
	return (y >= r || x >= c || y < 0 || x < 0); 
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	
	for(int i=0; i<r; i++){
		cin >> board[i];
	}
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(board[i][j] == 'F'){
				Q.push(make_tuple(i, j, 'F'));
			}
		}
	}
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(board[i][j] == 'J'){
				Q.push(make_tuple(i, j, 'J'));
				dist[i][j] = 1;
			}
		}
	}
	
	while(!Q.empty()){
		int y, x;
		char z;
		tie(y, x, z) = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(z == 'J'){
				if(OOB(ny, nx)){
					cout << dist[y][x];
					return 0;
				}
				if(dist[ny][nx] != 0 || board[ny][nx] != '.') continue;
				dist[ny][nx] = dist[y][x] + 1;
				Q.push(make_tuple(ny, nx, z)); 
			}
			else if(z == 'F'){
				if(OOB(ny, nx)) continue;
				if(dist[ny][nx] != 0 || board[ny][nx] != '.') continue;
				dist[ny][nx] = -1;
				Q.push(make_tuple(ny, nx, 'F'));
			}
		}
	}
	
	cout << "IMPOSSIBLE";
	return 0;
}
