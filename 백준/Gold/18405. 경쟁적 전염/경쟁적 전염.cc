#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, k;
int s, X, Y;
int board[201][201];
int t[201][201];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= n);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			cin >> board[y][x];
		}
	}
	
	cin >> s >> X >> Y;
	
	for(int p=1; p<=k; p++){
		for(int y=0; y<n; y++){
			for(int x=0; x<n; x++){
				if(board[y][x] == p) q.push({y,x});
			}
		}
	}
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		int num = board[cur.Y][cur.X];
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(board[ny][nx] != 0) continue;
			if(t[cur.Y][cur.X] < s){
				board[ny][nx] = num;
				if(t[cur.Y][cur.X] < s-1){
					t[ny][nx] = t[cur.Y][cur.X] + 1;
					q.push({ny,nx});
				}
			}
		}	
	}
	
	cout << board[X-1][Y-1];
	return 0;
}