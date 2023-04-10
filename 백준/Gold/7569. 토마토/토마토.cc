#include <bits/stdc++.h>

using namespace std;

int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1 ,-1};
int m, n, h;
int board[101][101][101];
queue<tuple<int, int, int>> Q;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie();
	
	cin >> m >> n >> h;
	
	for(int z=0; z<h; z++){
		for(int y=0; y<n; y++){
			for(int x=0; x<m; x++){
				cin >> board[z][y][x];
			}
		}
	}
	
	for(int z=0; z<h; z++){
		for(int y=0; y<n; y++){
			for(int x=0; x<m; x++){
				if(board[z][y][x] == 1) Q.push(make_tuple(z, y, x));
			}
		}
	}
	
	while(!Q.empty()){
		int cz = get<0>(Q.front());
		int cy = get<1>(Q.front());
		int cx = get<2>(Q.front()); 
		Q.pop();
		for(int i=0; i<6; i++){
			int nz = cz + dz[i];
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;
			if(board[nz][ny][nx] != 0) continue;
			board[nz][ny][nx] = board[cz][cy][cx] + 1;
			Q.push(make_tuple(nz, ny, nx));
		}
	}	
	
	int answer = -1;
	for(int z=0; z<h; z++){
		for(int y=0; y<n; y++){
			for(int x=0; x<m; x++){
				if(board[z][y][x] == 0){
					cout << -1;
					return 0;
				}
				else answer = max(answer, board[z][y][x]);
			}
		}
	}
	
	cout << answer - 1;
	return 0;
}