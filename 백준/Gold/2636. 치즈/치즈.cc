#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int board[102][102];
int t[102][102];
int y, x;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int mx = -1, cnt;

bool OOB(int ny, int nx){
	return (ny < 0 || nx < 0 || ny >= y || nx >= x);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> y >> x;
	
	for(int i=0; i<y; i++){
		fill(t[i], t[i]+x, 0x3f3f3f3f);
	}
	
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			cin >> board[i][j];
		}
	}
	
	q.push({0, 0});
	t[0][0] = 0;
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(OOB(ny, nx)) continue;
			if(t[ny][nx] <= t[cur.Y][cur.X]) continue;
		
			if(board[ny][nx] == 0){
				t[ny][nx] = t[cur.Y][cur.X];
			}
			else if(board[ny][nx] == 1){
				t[ny][nx] = t[cur.Y][cur.X] + 1;
			}
			q.push({ny, nx});
		}
	}
	
	 
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			if(board[i][j] == 1 && t[i][j] > mx){
				mx = t[i][j];
				cnt = 1;
			}
			else if(board[i][j] == 1 && t[i][j] == mx) cnt++;
		}
	}
	if(mx == 0) cnt = 0;
	cout << mx << '\n' << cnt;
	return 0;
}