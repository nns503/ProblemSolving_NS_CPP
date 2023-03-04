#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int board[51][51];
int temp[51][51];
int r, c, T;
queue<pair<int ,int>> Q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0 ,-1, 0};

bool isOut(int y, int x){
	return (y<0||x<0||y>=r||x>=c);
}

void copyMap(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			temp[i][j] = board[i][j];
	}
}

void setDust(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(board[i][j]>0){
				Q.push({i, j});
			}
		}
	}	
}

void moveDust(){
	setDust();
	copyMap();
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		int cnt = 0;
		int dust = temp[cur.Y][cur.X]; 
		for(int i=0; i<4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(isOut(ny, nx)) continue;
			if(board[ny][nx]==-1) continue;
			board[ny][nx]+=dust/5;
			cnt++; 
		}
		board[cur.Y][cur.X] -= dust/5*cnt;
	}
}

void moveClean(){
	copyMap();
	int up;
	int down;
	for(int y=0; y<r; y++){
		if(board[y][0]==-1){
			up = y;
			down = y+1;
			break;
		}
	}
	int nu = up;
	int nd = down;
	board[nu][1] = 0; 
	board[nd][1] = 0;
	
	for(int x=2; x<c; x++){
		board[nu][x] = temp[nu][x-1]; 
		board[nd][x] = temp[nd][x-1];
	}
	
	for(int y=nu-1; y>=0; y--){
		board[y][c-1] = temp[y+1][c-1]; 
	}
	for(int y=nd+1; y<r; y++){
		board[y][c-1] = temp[y-1][c-1]; 
	}	
	
	for(int x=c-2; x>=0; x--){
		board[0][x] = temp[0][x+1]; 
		board[r-1][x] = temp[r-1][x+1];
	}	
	
	for(int y=1; y<up; y++){
		board[y][0] = temp[y-1][0]; 
	}
	for(int y=r-2; y>down; y--){
		board[y][0] = temp[y+1][0]; 
	}					
}

int getDust(){
	int dust = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			if(board[i][j]>0) dust+=board[i][j];
	}
	return dust;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> T;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> board[i][j];
		}
	}
	while(T--){
		moveDust();
		moveClean();
	}
	cout << getDust();
	return 0;
}