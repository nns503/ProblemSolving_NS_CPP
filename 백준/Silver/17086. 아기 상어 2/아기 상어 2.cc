#include <bits/stdc++.h>
#define Y first
#define X second
using namespace std;

int n, m;
int board[51][51];
int len[51][51];
int dy[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dx[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int answer;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= m);
}

int BFS(int y, int x){
	queue<pair<int, int>> q;
	for(int i=0; i<n; i++){
		fill(len[i], len[i]+m+1, -1);
	}
	
	q.push({y, x});
	len[y][x] = 0;
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<8; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(len[ny][nx] != -1) continue;
			if(board[ny][nx] == 1){
				return len[cur.Y][cur.X] + 1;
			}
			if(board[ny][nx] == 0){
				len[ny][nx] = len[cur.Y][cur.X] + 1;
				q.push({ny, nx});
			}
		}	
	}
	
	return 0;	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cin >> board[y][x];
		}
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(board[y][x] == 1) continue;
			answer = max(answer, BFS(y, x));
		}
	}
	
	cout << answer;

	return 0;
}