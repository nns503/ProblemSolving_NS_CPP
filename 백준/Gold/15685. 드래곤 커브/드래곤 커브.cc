#include <bits/stdc++.h>

int n;
int x,y,d,g;
bool board[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int mv[2500];

using namespace std;

void setDC(){
	int cnt = 1;
	board[y][x] = true;
	x += dx[d];
	y += dy[d];
	mv[cnt] = d;
	board[y][x] = true;
	while(g--){
		int record = cnt;
		for(int i=cnt ; i>=1 ; i--){
			record++;
			int dir = (mv[i]+1)%4;
			
			x += dx[dir];
			y += dy[dir];
			board[y][x] = true;
			mv[record] = dir;
		}
		cnt *= 2;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	while(n--){
		cin >> x >> y >> d >> g;
		setDC();
	}
	
	int answer = 0;
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(board[i][j]&&board[i+1][j]&&board[i][j+1]&&board[i+1][j+1]) answer++;
		}
	}
	
	cout << answer;
	return 0;
}

