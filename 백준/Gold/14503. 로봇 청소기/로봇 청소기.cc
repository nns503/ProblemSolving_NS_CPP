#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int board[51][51];
bool vis[51][51];
int r, c, d;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> r >> c >> d;
	
	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			cin >> board[y][x];
		}
	}
	
	q.push({r, c});
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		if(!vis[cur.Y][cur.X]){
			vis[cur.Y][cur.X] = true;
			answer++;
		}
		
		int chk = true;
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(board[ny][nx] == 0 && vis[ny][nx] == false) chk = false;
		}
		
		if(chk){
			int ny = cur.Y + dy[(d+2)%4];
			int nx = cur.X + dx[(d+2)%4];
			if(board[ny][nx] == 1){
				cout << answer;
				return 0;
			}
			else{
				q.push({ny, nx});
			}
		}
		else if(!chk){
			for(int i=0; i<4; i++){
				d = (d+3) % 4;
				int ny = cur.Y + dy[d];
				int nx = cur.X + dx[d];	
				if(board[ny][nx] == 1 || vis[ny][nx] == true) continue;
				q.push({ny, nx});
				break;			
			}
		}
	}
	
	return 0;
}