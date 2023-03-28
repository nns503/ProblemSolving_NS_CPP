#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int result = 1000000;
int n;
int number = 2;
int board[101][101];
int dis[101][101];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int ,int>> Q;

void setBoard(int y, int x){
	board[y][x] = number;
	Q.push({y, x});
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(board[ny][nx] != 1) continue;
			board[ny][nx] = number;
			Q.push({ny, nx});
		}
	}
	number++;
}

void getDistance(int y, int x){
	queue<pair<int ,int>> D;
	for(int i=0; i<n; i++) fill(dis[i], dis[i] + n, -1);
	dis[y][x] = 0;
	D.push({y, x});
	while(!D.empty()){
		pair<int, int> cur = D.front(); D.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(board[ny][nx] == board[y][x] || dis[ny][nx] != -1) continue;
			if(board[ny][nx] == 0){		
				dis[ny][nx] = dis[cur.Y][cur.X] + 1;
				D.push({ny, nx});
			}
			else{
				result = min(result, dis[cur.Y][cur.X]);
				return;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
		}
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			if(board[y][x] == 1) setBoard(y, x);
		}
	}

	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			if(board[y][x] != 0) getDistance(y, x);
		}
	}	
	
	cout << result;
	
	return 0;
}