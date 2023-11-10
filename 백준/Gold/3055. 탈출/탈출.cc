#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int r, c;
string board[51];
int s_t[51][51];
int w_t[51][51];
queue<pair<int, int>> s;
queue<pair<int, int>> w;
int dy[4] = {-1 ,1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= r || x >= c);
}

void BFS_w(){
	while(!w.empty()){
		auto cur = w.front(); w.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + cur.Y;
			int nx = dx[i] + cur.X;
			if(OOB(ny, nx)) continue;
			if(w_t[ny][nx] <= w_t[cur.Y][cur.X] + 1) continue;
			if(board[ny][nx] != 'S' && board[ny][nx] != '.') continue;
			w_t[ny][nx] =  w_t[cur.Y][cur.X] + 1;
			w.push({ny, nx});
		}
	}	
}


void BFS_s(){
	while(!s.empty()){
		auto cur = s.front(); s.pop();
		for(int i=0; i<4; i++){
			int ny = dy[i] + cur.Y;
			int nx = dx[i] + cur.X;
			if(OOB(ny, nx)) continue;
			if(s_t[ny][nx] <= s_t[cur.Y][cur.X] + 1) continue;
			if(board[ny][nx] != 'D' && board[ny][nx] != '.') continue;
			if(s_t[cur.Y][cur.X] + 1 >= w_t[ny][nx]) continue;
			s_t[ny][nx] =  s_t[cur.Y][cur.X] + 1;
			s.push({ny, nx});
		}
	}	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	
	for(int y=0; y<r; y++){
		cin >> board[y];
	}
	

	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(board[y][x] == 'S'){
				s.push({y, x});
				s_t[y][x] = 0;
			}
			else s_t[y][x] = 1000;
		}
	}
	
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(board[y][x] == '*'){
				w.push({y, x});
				w_t[y][x] = 0;
			}
			else w_t[y][x] = 1000;
		}
	}
	
	BFS_w();
	BFS_s();
		
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(board[y][x] == 'D'){
				if(s_t[y][x] == 1000) cout << "KAKTUS";
				else cout << s_t[y][x];
			}
		}
	}

	
}